import rospy
import numpy
import math

class BasePlatform:
    def __init__(self,r):
        # angle
        self.sigma1 = 0
        self.sigma2 = 0
        self.sigma3 = 0
        # velocity
        self.v1 = 0
        self.v2 = 0
        self.v3 = 0
        # angle to the center of mass
        self.alpha1 = 0
        self.alpha2 = math.radians(60)
        self.alpha3 = math.radians(300)
        self.r = r
        self.phi = 0;
    def LineMove(self,move_angle,velocity):
        self.sigma1 = move_angle
        self.sigma2 = move_angle
        self.sigma3 = move_angle
        self.v1 = self.v2 = self.v3 = velocity

    def CircleMove(self,Velocity):
        self.sigma1 = 90;
        self.sigma2 = 30;
        self.sigma3 = 330;
        self.v1 = self.v2 = self.v3 = Velocity;
    
    def CompoundMove(self,v_x,v_y,w):
        tf = numpy.array([[1,0,0],
                          [0,1,self.r],
                          [1,0,self.r*math.sin(self.alpha2)],
                          [0,1,self.r*math.cos(self.alpha3)],
                          [1,0,self.r*math.sin(self.alpha3)],
                          [0,1,self.r*math.cos(self.alpha3)]
                          ],dtype = float)
        v_xyw = numpy.array([[v_x],[v_y],[w]],dtype = float)
        v_i_component = tf.dot(v_xyw);
        v_i = self.__vCompute(v_i_component);
        sigma_i = self.__sigmaCompute(v_i_component);



    def __vCompute(self,v_i_component):
        size_a_b = v_i_component.size
        
        count = 0;
        tmp = 0;
        flag = 0;
        
        v = numpy.zeros([int(size_a_b),1])
        for i in range(0,size_a_b-1):
            count = count + 1
            num1 = float(v_i_component[i,0])
            tmp = tmp +(num1)*(num1);
            if count == 1:
                continue
            else:
                v[flag]= math.sqrt(tmp);
                flag = flag +1;
                count =0
                tmp = 0
        return v

    def __sigmaCompute(self,v_i_component):
        size_a_b = v_i_component.size
        sigma = numpy.zeros([size_a_b,1])
        flag = 0;
        
        for i in range(0,size_a_b-1,2):
            sigma[flag] = math.atan(float(v_i_component[i,0])/float(v_i_component[i+1,0]))                
            flag = flag + 1        
        return sigma


    def ShowInfo(self):
        print("################################")
        print("角度参数信息")
        print("舵轮1的滑移角:",self.sigma1)
        print("舵轮2的滑移角:",self.sigma2)
        print("舵轮3的滑移角:",self.sigma3)
        print(">>>>>>>")
        print("速度参数信息")
        print("舵轮1的速度:",self.v1)
        print("舵轮1的速度:",self.v2)
        print("舵轮1的速度:",self.v3)

    
    
    
    
if __name__ == '__main__':
    # Create the object of the BasePlatform
    car1 = BasePlatform(54)
    car1.LineMove(30,10)
    car1.ShowInfo()
    car1.CompoundMove(1,1,1)
    rospy.init_node("MoveBase",)
    
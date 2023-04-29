;; Auto-generated. Do not edit!


(when (boundp 'rbc_2023::UI2node)
  (if (not (find-package "RBC_2023"))
    (make-package "RBC_2023"))
  (shadow 'UI2node (find-package "RBC_2023")))
(unless (find-package "RBC_2023::UI2NODE")
  (make-package "RBC_2023::UI2NODE"))

(in-package "ROS")
;;//! \htmlinclude UI2node.msg.html


(defclass rbc_2023::UI2node
  :super ros::object
  :slots (_mode _isCheckShowWrite _isCheckShowRead _data ))

(defmethod rbc_2023::UI2node
  (:init
   (&key
    ((:mode __mode) 0)
    ((:isCheckShowWrite __isCheckShowWrite) nil)
    ((:isCheckShowRead __isCheckShowRead) nil)
    ((:data __data) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _mode (round __mode))
   (setq _isCheckShowWrite __isCheckShowWrite)
   (setq _isCheckShowRead __isCheckShowRead)
   (setq _data __data)
   self)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:isCheckShowWrite
   (&optional (__isCheckShowWrite :null))
   (if (not (eq __isCheckShowWrite :null)) (setq _isCheckShowWrite __isCheckShowWrite)) _isCheckShowWrite)
  (:isCheckShowRead
   (&optional (__isCheckShowRead :null))
   (if (not (eq __isCheckShowRead :null)) (setq _isCheckShowRead __isCheckShowRead)) _isCheckShowRead)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; int32 _mode
    4
    ;; bool _isCheckShowWrite
    1
    ;; bool _isCheckShowRead
    1
    ;; int32[] _data
    (* 4    (length _data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _mode
       (write-long _mode s)
     ;; bool _isCheckShowWrite
       (if _isCheckShowWrite (write-byte -1 s) (write-byte 0 s))
     ;; bool _isCheckShowRead
       (if _isCheckShowRead (write-byte -1 s) (write-byte 0 s))
     ;; int32[] _data
     (write-long (length _data) s)
     (dotimes (i (length _data))
       (write-long (elt _data i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _mode
     (setq _mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _isCheckShowWrite
     (setq _isCheckShowWrite (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _isCheckShowRead
     (setq _isCheckShowRead (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32[] _data
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _data (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _data i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get rbc_2023::UI2node :md5sum-) "3929c6344e36b839b0a0e74ac70b59cf")
(setf (get rbc_2023::UI2node :datatype-) "rbc_2023/UI2node")
(setf (get rbc_2023::UI2node :definition-)
      "int32 mode
bool isCheckShowWrite
bool isCheckShowRead
int32[] data
")



(provide :rbc_2023/UI2node "3929c6344e36b839b0a0e74ac70b59cf")



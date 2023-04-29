; Auto-generated. Do not edit!


(cl:in-package rbc_2023-msg)


;//! \htmlinclude UI2node.msg.html

(cl:defclass <UI2node> (roslisp-msg-protocol:ros-message)
  ((mode
    :reader mode
    :initarg :mode
    :type cl:integer
    :initform 0)
   (isCheckShowWrite
    :reader isCheckShowWrite
    :initarg :isCheckShowWrite
    :type cl:boolean
    :initform cl:nil)
   (isCheckShowRead
    :reader isCheckShowRead
    :initarg :isCheckShowRead
    :type cl:boolean
    :initform cl:nil)
   (data
    :reader data
    :initarg :data
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass UI2node (<UI2node>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UI2node>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UI2node)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rbc_2023-msg:<UI2node> is deprecated: use rbc_2023-msg:UI2node instead.")))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <UI2node>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:mode-val is deprecated.  Use rbc_2023-msg:mode instead.")
  (mode m))

(cl:ensure-generic-function 'isCheckShowWrite-val :lambda-list '(m))
(cl:defmethod isCheckShowWrite-val ((m <UI2node>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:isCheckShowWrite-val is deprecated.  Use rbc_2023-msg:isCheckShowWrite instead.")
  (isCheckShowWrite m))

(cl:ensure-generic-function 'isCheckShowRead-val :lambda-list '(m))
(cl:defmethod isCheckShowRead-val ((m <UI2node>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:isCheckShowRead-val is deprecated.  Use rbc_2023-msg:isCheckShowRead instead.")
  (isCheckShowRead m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <UI2node>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:data-val is deprecated.  Use rbc_2023-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UI2node>) ostream)
  "Serializes a message object of type '<UI2node>"
  (cl:let* ((signed (cl:slot-value msg 'mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isCheckShowWrite) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isCheckShowRead) 1 0)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UI2node>) istream)
  "Deserializes a message object of type '<UI2node>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:slot-value msg 'isCheckShowWrite) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'isCheckShowRead) (cl:not (cl:zerop (cl:read-byte istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'data) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UI2node>)))
  "Returns string type for a message object of type '<UI2node>"
  "rbc_2023/UI2node")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UI2node)))
  "Returns string type for a message object of type 'UI2node"
  "rbc_2023/UI2node")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UI2node>)))
  "Returns md5sum for a message object of type '<UI2node>"
  "3929c6344e36b839b0a0e74ac70b59cf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UI2node)))
  "Returns md5sum for a message object of type 'UI2node"
  "3929c6344e36b839b0a0e74ac70b59cf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UI2node>)))
  "Returns full string definition for message of type '<UI2node>"
  (cl:format cl:nil "int32 mode~%bool isCheckShowWrite~%bool isCheckShowRead~%int32[] data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UI2node)))
  "Returns full string definition for message of type 'UI2node"
  (cl:format cl:nil "int32 mode~%bool isCheckShowWrite~%bool isCheckShowRead~%int32[] data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UI2node>))
  (cl:+ 0
     4
     1
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UI2node>))
  "Converts a ROS message object to a list"
  (cl:list 'UI2node
    (cl:cons ':mode (mode msg))
    (cl:cons ':isCheckShowWrite (isCheckShowWrite msg))
    (cl:cons ':isCheckShowRead (isCheckShowRead msg))
    (cl:cons ':data (data msg))
))

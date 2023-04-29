; Auto-generated. Do not edit!


(cl:in-package rbc_2023-msg)


;//! \htmlinclude xy.msg.html

(cl:defclass <xy> (roslisp-msg-protocol:ros-message)
  ((V
    :reader V
    :initarg :V
    :type cl:string
    :initform ""))
)

(cl:defclass xy (<xy>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <xy>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'xy)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rbc_2023-msg:<xy> is deprecated: use rbc_2023-msg:xy instead.")))

(cl:ensure-generic-function 'V-val :lambda-list '(m))
(cl:defmethod V-val ((m <xy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:V-val is deprecated.  Use rbc_2023-msg:V instead.")
  (V m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <xy>) ostream)
  "Serializes a message object of type '<xy>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'V))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'V))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <xy>) istream)
  "Deserializes a message object of type '<xy>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'V) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'V) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<xy>)))
  "Returns string type for a message object of type '<xy>"
  "rbc_2023/xy")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'xy)))
  "Returns string type for a message object of type 'xy"
  "rbc_2023/xy")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<xy>)))
  "Returns md5sum for a message object of type '<xy>"
  "18370905db842ff9f15c0610f2c0d8e2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'xy)))
  "Returns md5sum for a message object of type 'xy"
  "18370905db842ff9f15c0610f2c0d8e2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<xy>)))
  "Returns full string definition for message of type '<xy>"
  (cl:format cl:nil "string V~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'xy)))
  "Returns full string definition for message of type 'xy"
  (cl:format cl:nil "string V~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <xy>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'V))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <xy>))
  "Converts a ROS message object to a list"
  (cl:list 'xy
    (cl:cons ':V (V msg))
))

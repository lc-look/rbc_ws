; Auto-generated. Do not edit!


(cl:in-package rbc_2023-msg)


;//! \htmlinclude recive.msg.html

(cl:defclass <recive> (roslisp-msg-protocol:ros-message)
  ((LaunchSpeed
    :reader LaunchSpeed
    :initarg :LaunchSpeed
    :type cl:float
    :initform 0.0))
)

(cl:defclass recive (<recive>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <recive>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'recive)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rbc_2023-msg:<recive> is deprecated: use rbc_2023-msg:recive instead.")))

(cl:ensure-generic-function 'LaunchSpeed-val :lambda-list '(m))
(cl:defmethod LaunchSpeed-val ((m <recive>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:LaunchSpeed-val is deprecated.  Use rbc_2023-msg:LaunchSpeed instead.")
  (LaunchSpeed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <recive>) ostream)
  "Serializes a message object of type '<recive>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'LaunchSpeed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <recive>) istream)
  "Deserializes a message object of type '<recive>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'LaunchSpeed) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<recive>)))
  "Returns string type for a message object of type '<recive>"
  "rbc_2023/recive")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'recive)))
  "Returns string type for a message object of type 'recive"
  "rbc_2023/recive")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<recive>)))
  "Returns md5sum for a message object of type '<recive>"
  "ad511b29776a364dc3562d699cb5c9b0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'recive)))
  "Returns md5sum for a message object of type 'recive"
  "ad511b29776a364dc3562d699cb5c9b0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<recive>)))
  "Returns full string definition for message of type '<recive>"
  (cl:format cl:nil "float64 LaunchSpeed~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'recive)))
  "Returns full string definition for message of type 'recive"
  (cl:format cl:nil "float64 LaunchSpeed~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <recive>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <recive>))
  "Converts a ROS message object to a list"
  (cl:list 'recive
    (cl:cons ':LaunchSpeed (LaunchSpeed msg))
))

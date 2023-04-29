; Auto-generated. Do not edit!


(cl:in-package rbc_2023-msg)


;//! \htmlinclude ui2Node.msg.html

(cl:defclass <ui2Node> (roslisp-msg-protocol:ros-message)
  ((mode
    :reader mode
    :initarg :mode
    :type cl:integer
    :initform 0)
   (isCheckOutputFile
    :reader isCheckOutputFile
    :initarg :isCheckOutputFile
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ui2Node (<ui2Node>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ui2Node>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ui2Node)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rbc_2023-msg:<ui2Node> is deprecated: use rbc_2023-msg:ui2Node instead.")))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <ui2Node>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:mode-val is deprecated.  Use rbc_2023-msg:mode instead.")
  (mode m))

(cl:ensure-generic-function 'isCheckOutputFile-val :lambda-list '(m))
(cl:defmethod isCheckOutputFile-val ((m <ui2Node>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:isCheckOutputFile-val is deprecated.  Use rbc_2023-msg:isCheckOutputFile instead.")
  (isCheckOutputFile m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ui2Node>) ostream)
  "Serializes a message object of type '<ui2Node>"
  (cl:let* ((signed (cl:slot-value msg 'mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isCheckOutputFile) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ui2Node>) istream)
  "Deserializes a message object of type '<ui2Node>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:slot-value msg 'isCheckOutputFile) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ui2Node>)))
  "Returns string type for a message object of type '<ui2Node>"
  "rbc_2023/ui2Node")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ui2Node)))
  "Returns string type for a message object of type 'ui2Node"
  "rbc_2023/ui2Node")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ui2Node>)))
  "Returns md5sum for a message object of type '<ui2Node>"
  "ea55bf909381703fa612669f10560103")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ui2Node)))
  "Returns md5sum for a message object of type 'ui2Node"
  "ea55bf909381703fa612669f10560103")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ui2Node>)))
  "Returns full string definition for message of type '<ui2Node>"
  (cl:format cl:nil "int32 mode~%bool isCheckOutputFile~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ui2Node)))
  "Returns full string definition for message of type 'ui2Node"
  (cl:format cl:nil "int32 mode~%bool isCheckOutputFile~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ui2Node>))
  (cl:+ 0
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ui2Node>))
  "Converts a ROS message object to a list"
  (cl:list 'ui2Node
    (cl:cons ':mode (mode msg))
    (cl:cons ':isCheckOutputFile (isCheckOutputFile msg))
))

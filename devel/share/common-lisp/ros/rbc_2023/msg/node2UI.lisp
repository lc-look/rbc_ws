; Auto-generated. Do not edit!


(cl:in-package rbc_2023-msg)


;//! \htmlinclude node2UI.msg.html

(cl:defclass <node2UI> (roslisp-msg-protocol:ros-message)
  ((mode
    :reader mode
    :initarg :mode
    :type cl:integer
    :initform 0)
   (data
    :reader data
    :initarg :data
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (backStr
    :reader backStr
    :initarg :backStr
    :type cl:string
    :initform "")
   (rawStr
    :reader rawStr
    :initarg :rawStr
    :type cl:string
    :initform ""))
)

(cl:defclass node2UI (<node2UI>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <node2UI>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'node2UI)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rbc_2023-msg:<node2UI> is deprecated: use rbc_2023-msg:node2UI instead.")))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <node2UI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:mode-val is deprecated.  Use rbc_2023-msg:mode instead.")
  (mode m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <node2UI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:data-val is deprecated.  Use rbc_2023-msg:data instead.")
  (data m))

(cl:ensure-generic-function 'backStr-val :lambda-list '(m))
(cl:defmethod backStr-val ((m <node2UI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:backStr-val is deprecated.  Use rbc_2023-msg:backStr instead.")
  (backStr m))

(cl:ensure-generic-function 'rawStr-val :lambda-list '(m))
(cl:defmethod rawStr-val ((m <node2UI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rbc_2023-msg:rawStr-val is deprecated.  Use rbc_2023-msg:rawStr instead.")
  (rawStr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <node2UI>) ostream)
  "Serializes a message object of type '<node2UI>"
  (cl:let* ((signed (cl:slot-value msg 'mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
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
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'backStr))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'backStr))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'rawStr))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'rawStr))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <node2UI>) istream)
  "Deserializes a message object of type '<node2UI>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
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
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'backStr) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'backStr) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'rawStr) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'rawStr) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<node2UI>)))
  "Returns string type for a message object of type '<node2UI>"
  "rbc_2023/node2UI")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'node2UI)))
  "Returns string type for a message object of type 'node2UI"
  "rbc_2023/node2UI")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<node2UI>)))
  "Returns md5sum for a message object of type '<node2UI>"
  "57e20d8a0746f7d6680c3406f4a78eb2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'node2UI)))
  "Returns md5sum for a message object of type 'node2UI"
  "57e20d8a0746f7d6680c3406f4a78eb2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<node2UI>)))
  "Returns full string definition for message of type '<node2UI>"
  (cl:format cl:nil "int32 mode~%int32[] data~%string backStr~%string rawStr~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'node2UI)))
  "Returns full string definition for message of type 'node2UI"
  (cl:format cl:nil "int32 mode~%int32[] data~%string backStr~%string rawStr~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <node2UI>))
  (cl:+ 0
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:length (cl:slot-value msg 'backStr))
     4 (cl:length (cl:slot-value msg 'rawStr))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <node2UI>))
  "Converts a ROS message object to a list"
  (cl:list 'node2UI
    (cl:cons ':mode (mode msg))
    (cl:cons ':data (data msg))
    (cl:cons ':backStr (backStr msg))
    (cl:cons ':rawStr (rawStr msg))
))

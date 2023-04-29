;; Auto-generated. Do not edit!


(when (boundp 'rbc_2023::node2UI)
  (if (not (find-package "RBC_2023"))
    (make-package "RBC_2023"))
  (shadow 'node2UI (find-package "RBC_2023")))
(unless (find-package "RBC_2023::NODE2UI")
  (make-package "RBC_2023::NODE2UI"))

(in-package "ROS")
;;//! \htmlinclude node2UI.msg.html


(defclass rbc_2023::node2UI
  :super ros::object
  :slots (_mode _data _backStr _rawStr ))

(defmethod rbc_2023::node2UI
  (:init
   (&key
    ((:mode __mode) 0)
    ((:data __data) (make-array 0 :initial-element 0 :element-type :integer))
    ((:backStr __backStr) "")
    ((:rawStr __rawStr) "")
    )
   (send-super :init)
   (setq _mode (round __mode))
   (setq _data __data)
   (setq _backStr (string __backStr))
   (setq _rawStr (string __rawStr))
   self)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:backStr
   (&optional __backStr)
   (if __backStr (setq _backStr __backStr)) _backStr)
  (:rawStr
   (&optional __rawStr)
   (if __rawStr (setq _rawStr __rawStr)) _rawStr)
  (:serialization-length
   ()
   (+
    ;; int32 _mode
    4
    ;; int32[] _data
    (* 4    (length _data)) 4
    ;; string _backStr
    4 (length _backStr)
    ;; string _rawStr
    4 (length _rawStr)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _mode
       (write-long _mode s)
     ;; int32[] _data
     (write-long (length _data) s)
     (dotimes (i (length _data))
       (write-long (elt _data i) s)
       )
     ;; string _backStr
       (write-long (length _backStr) s) (princ _backStr s)
     ;; string _rawStr
       (write-long (length _rawStr) s) (princ _rawStr s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _mode
     (setq _mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32[] _data
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _data (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _data i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; string _backStr
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _backStr (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _rawStr
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _rawStr (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get rbc_2023::node2UI :md5sum-) "57e20d8a0746f7d6680c3406f4a78eb2")
(setf (get rbc_2023::node2UI :datatype-) "rbc_2023/node2UI")
(setf (get rbc_2023::node2UI :definition-)
      "int32 mode
int32[] data
string backStr
string rawStr
")



(provide :rbc_2023/node2UI "57e20d8a0746f7d6680c3406f4a78eb2")



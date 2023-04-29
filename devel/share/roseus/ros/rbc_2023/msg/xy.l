;; Auto-generated. Do not edit!


(when (boundp 'rbc_2023::xy)
  (if (not (find-package "RBC_2023"))
    (make-package "RBC_2023"))
  (shadow 'xy (find-package "RBC_2023")))
(unless (find-package "RBC_2023::XY")
  (make-package "RBC_2023::XY"))

(in-package "ROS")
;;//! \htmlinclude xy.msg.html


(defclass rbc_2023::xy
  :super ros::object
  :slots (_V ))

(defmethod rbc_2023::xy
  (:init
   (&key
    ((:V __V) "")
    )
   (send-super :init)
   (setq _V (string __V))
   self)
  (:V
   (&optional __V)
   (if __V (setq _V __V)) _V)
  (:serialization-length
   ()
   (+
    ;; string _V
    4 (length _V)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _V
       (write-long (length _V) s) (princ _V s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _V
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _V (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get rbc_2023::xy :md5sum-) "18370905db842ff9f15c0610f2c0d8e2")
(setf (get rbc_2023::xy :datatype-) "rbc_2023/xy")
(setf (get rbc_2023::xy :definition-)
      "string V
")



(provide :rbc_2023/xy "18370905db842ff9f15c0610f2c0d8e2")



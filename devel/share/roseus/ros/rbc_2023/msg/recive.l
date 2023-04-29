;; Auto-generated. Do not edit!


(when (boundp 'rbc_2023::recive)
  (if (not (find-package "RBC_2023"))
    (make-package "RBC_2023"))
  (shadow 'recive (find-package "RBC_2023")))
(unless (find-package "RBC_2023::RECIVE")
  (make-package "RBC_2023::RECIVE"))

(in-package "ROS")
;;//! \htmlinclude recive.msg.html


(defclass rbc_2023::recive
  :super ros::object
  :slots (_LaunchSpeed ))

(defmethod rbc_2023::recive
  (:init
   (&key
    ((:LaunchSpeed __LaunchSpeed) 0.0)
    )
   (send-super :init)
   (setq _LaunchSpeed (float __LaunchSpeed))
   self)
  (:LaunchSpeed
   (&optional __LaunchSpeed)
   (if __LaunchSpeed (setq _LaunchSpeed __LaunchSpeed)) _LaunchSpeed)
  (:serialization-length
   ()
   (+
    ;; float64 _LaunchSpeed
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _LaunchSpeed
       (sys::poke _LaunchSpeed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _LaunchSpeed
     (setq _LaunchSpeed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get rbc_2023::recive :md5sum-) "ad511b29776a364dc3562d699cb5c9b0")
(setf (get rbc_2023::recive :datatype-) "rbc_2023/recive")
(setf (get rbc_2023::recive :definition-)
      "float64 LaunchSpeed
")



(provide :rbc_2023/recive "ad511b29776a364dc3562d699cb5c9b0")



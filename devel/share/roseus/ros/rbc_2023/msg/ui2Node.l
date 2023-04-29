;; Auto-generated. Do not edit!


(when (boundp 'rbc_2023::ui2Node)
  (if (not (find-package "RBC_2023"))
    (make-package "RBC_2023"))
  (shadow 'ui2Node (find-package "RBC_2023")))
(unless (find-package "RBC_2023::UI2NODE")
  (make-package "RBC_2023::UI2NODE"))

(in-package "ROS")
;;//! \htmlinclude ui2Node.msg.html


(defclass rbc_2023::ui2Node
  :super ros::object
  :slots (_mode _isCheckOutputFile ))

(defmethod rbc_2023::ui2Node
  (:init
   (&key
    ((:mode __mode) 0)
    ((:isCheckOutputFile __isCheckOutputFile) nil)
    )
   (send-super :init)
   (setq _mode (round __mode))
   (setq _isCheckOutputFile __isCheckOutputFile)
   self)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:isCheckOutputFile
   (&optional (__isCheckOutputFile :null))
   (if (not (eq __isCheckOutputFile :null)) (setq _isCheckOutputFile __isCheckOutputFile)) _isCheckOutputFile)
  (:serialization-length
   ()
   (+
    ;; int32 _mode
    4
    ;; bool _isCheckOutputFile
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _mode
       (write-long _mode s)
     ;; bool _isCheckOutputFile
       (if _isCheckOutputFile (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _mode
     (setq _mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _isCheckOutputFile
     (setq _isCheckOutputFile (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get rbc_2023::ui2Node :md5sum-) "ea55bf909381703fa612669f10560103")
(setf (get rbc_2023::ui2Node :datatype-) "rbc_2023/ui2Node")
(setf (get rbc_2023::ui2Node :definition-)
      "int32 mode
bool isCheckOutputFile
")



(provide :rbc_2023/ui2Node "ea55bf909381703fa612669f10560103")




(cl:in-package :asdf)

(defsystem "rbc_2023-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "UI2node" :depends-on ("_package_UI2node"))
    (:file "_package_UI2node" :depends-on ("_package"))
    (:file "imu" :depends-on ("_package_imu"))
    (:file "_package_imu" :depends-on ("_package"))
    (:file "node2UI" :depends-on ("_package_node2UI"))
    (:file "_package_node2UI" :depends-on ("_package"))
    (:file "recive" :depends-on ("_package_recive"))
    (:file "_package_recive" :depends-on ("_package"))
    (:file "xy" :depends-on ("_package_xy"))
    (:file "_package_xy" :depends-on ("_package"))
  ))
// Generated by gencpp from file rbc_2023/ui2Node.msg
// DO NOT EDIT!


#ifndef RBC_2023_MESSAGE_UI2NODE_H
#define RBC_2023_MESSAGE_UI2NODE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rbc_2023
{
template <class ContainerAllocator>
struct ui2Node_
{
  typedef ui2Node_<ContainerAllocator> Type;

  ui2Node_()
    : mode(0)
    , isCheckOutputFile(false)  {
    }
  ui2Node_(const ContainerAllocator& _alloc)
    : mode(0)
    , isCheckOutputFile(false)  {
  (void)_alloc;
    }



   typedef int32_t _mode_type;
  _mode_type mode;

   typedef uint8_t _isCheckOutputFile_type;
  _isCheckOutputFile_type isCheckOutputFile;





  typedef boost::shared_ptr< ::rbc_2023::ui2Node_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rbc_2023::ui2Node_<ContainerAllocator> const> ConstPtr;

}; // struct ui2Node_

typedef ::rbc_2023::ui2Node_<std::allocator<void> > ui2Node;

typedef boost::shared_ptr< ::rbc_2023::ui2Node > ui2NodePtr;
typedef boost::shared_ptr< ::rbc_2023::ui2Node const> ui2NodeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rbc_2023::ui2Node_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rbc_2023::ui2Node_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::rbc_2023::ui2Node_<ContainerAllocator1> & lhs, const ::rbc_2023::ui2Node_<ContainerAllocator2> & rhs)
{
  return lhs.mode == rhs.mode &&
    lhs.isCheckOutputFile == rhs.isCheckOutputFile;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::rbc_2023::ui2Node_<ContainerAllocator1> & lhs, const ::rbc_2023::ui2Node_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace rbc_2023

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::rbc_2023::ui2Node_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rbc_2023::ui2Node_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rbc_2023::ui2Node_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rbc_2023::ui2Node_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rbc_2023::ui2Node_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rbc_2023::ui2Node_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rbc_2023::ui2Node_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ea55bf909381703fa612669f10560103";
  }

  static const char* value(const ::rbc_2023::ui2Node_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xea55bf909381703fULL;
  static const uint64_t static_value2 = 0xa612669f10560103ULL;
};

template<class ContainerAllocator>
struct DataType< ::rbc_2023::ui2Node_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rbc_2023/ui2Node";
  }

  static const char* value(const ::rbc_2023::ui2Node_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rbc_2023::ui2Node_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 mode\n"
"bool isCheckOutputFile\n"
;
  }

  static const char* value(const ::rbc_2023::ui2Node_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rbc_2023::ui2Node_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.mode);
      stream.next(m.isCheckOutputFile);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ui2Node_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rbc_2023::ui2Node_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rbc_2023::ui2Node_<ContainerAllocator>& v)
  {
    s << indent << "mode: ";
    Printer<int32_t>::stream(s, indent + "  ", v.mode);
    s << indent << "isCheckOutputFile: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.isCheckOutputFile);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RBC_2023_MESSAGE_UI2NODE_H

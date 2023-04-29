// Auto-generated. Do not edit!

// (in-package rbc_2023.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ui2Node {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.mode = null;
      this.isCheckOutputFile = null;
    }
    else {
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
      if (initObj.hasOwnProperty('isCheckOutputFile')) {
        this.isCheckOutputFile = initObj.isCheckOutputFile
      }
      else {
        this.isCheckOutputFile = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ui2Node
    // Serialize message field [mode]
    bufferOffset = _serializer.int32(obj.mode, buffer, bufferOffset);
    // Serialize message field [isCheckOutputFile]
    bufferOffset = _serializer.bool(obj.isCheckOutputFile, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ui2Node
    let len;
    let data = new ui2Node(null);
    // Deserialize message field [mode]
    data.mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [isCheckOutputFile]
    data.isCheckOutputFile = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rbc_2023/ui2Node';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ea55bf909381703fa612669f10560103';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 mode
    bool isCheckOutputFile
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ui2Node(null);
    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    if (msg.isCheckOutputFile !== undefined) {
      resolved.isCheckOutputFile = msg.isCheckOutputFile;
    }
    else {
      resolved.isCheckOutputFile = false
    }

    return resolved;
    }
};

module.exports = ui2Node;

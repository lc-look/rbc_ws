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

class node2UI {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.mode = null;
      this.data = null;
      this.backStr = null;
      this.rawStr = null;
    }
    else {
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = [];
      }
      if (initObj.hasOwnProperty('backStr')) {
        this.backStr = initObj.backStr
      }
      else {
        this.backStr = '';
      }
      if (initObj.hasOwnProperty('rawStr')) {
        this.rawStr = initObj.rawStr
      }
      else {
        this.rawStr = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type node2UI
    // Serialize message field [mode]
    bufferOffset = _serializer.int32(obj.mode, buffer, bufferOffset);
    // Serialize message field [data]
    bufferOffset = _arraySerializer.int32(obj.data, buffer, bufferOffset, null);
    // Serialize message field [backStr]
    bufferOffset = _serializer.string(obj.backStr, buffer, bufferOffset);
    // Serialize message field [rawStr]
    bufferOffset = _serializer.string(obj.rawStr, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type node2UI
    let len;
    let data = new node2UI(null);
    // Deserialize message field [mode]
    data.mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [backStr]
    data.backStr = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [rawStr]
    data.rawStr = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.data.length;
    length += _getByteLength(object.backStr);
    length += _getByteLength(object.rawStr);
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rbc_2023/node2UI';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '57e20d8a0746f7d6680c3406f4a78eb2';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 mode
    int32[] data
    string backStr
    string rawStr
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new node2UI(null);
    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = []
    }

    if (msg.backStr !== undefined) {
      resolved.backStr = msg.backStr;
    }
    else {
      resolved.backStr = ''
    }

    if (msg.rawStr !== undefined) {
      resolved.rawStr = msg.rawStr;
    }
    else {
      resolved.rawStr = ''
    }

    return resolved;
    }
};

module.exports = node2UI;

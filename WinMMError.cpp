#include "WinMMError.hpp"

#include <Windows.h>
#include <map>

static std::map<int32_t, std::string> MCIERR_NAMES = {
    {MCIERR_INVALID_DEVICE_ID, "MCIERR_INVALID_DEVICE_ID"},
    {MCIERR_UNRECOGNIZED_KEYWORD, "MCIERR_UNRECOGNIZED_KEYWORD"},
    {MCIERR_UNRECOGNIZED_COMMAND, "MCIERR_UNRECOGNIZED_COMMAND"},
    {MCIERR_HARDWARE, "MCIERR_HARDWARE"},
    {MCIERR_INVALID_DEVICE_NAME, "MCIERR_INVALID_DEVICE_NAME"},
    {MCIERR_OUT_OF_MEMORY, "MCIERR_OUT_OF_MEMORY"},
    {MCIERR_DEVICE_OPEN, "MCIERR_DEVICE_OPEN"},
    {MCIERR_CANNOT_LOAD_DRIVER, "MCIERR_CANNOT_LOAD_DRIVER"},
    {MCIERR_MISSING_COMMAND_STRING, "MCIERR_MISSING_COMMAND_STRING"},
    {MCIERR_PARAM_OVERFLOW, "MCIERR_PARAM_OVERFLOW"},
    {MCIERR_MISSING_STRING_ARGUMENT, "MCIERR_MISSING_STRING_ARGUMENT"},
    {MCIERR_BAD_INTEGER, "MCIERR_BAD_INTEGER"},
    {MCIERR_PARSER_INTERNAL, "MCIERR_PARSER_INTERNAL"},
    {MCIERR_DRIVER_INTERNAL, "MCIERR_DRIVER_INTERNAL"},
    {MCIERR_MISSING_PARAMETER, "MCIERR_MISSING_PARAMETER"},
    {MCIERR_UNSUPPORTED_FUNCTION, "MCIERR_UNSUPPORTED_FUNCTION"},
    {MCIERR_FILE_NOT_FOUND, "MCIERR_FILE_NOT_FOUND"},
    {MCIERR_DEVICE_NOT_READY, "MCIERR_DEVICE_NOT_READY"},
    {MCIERR_INTERNAL, "MCIERR_INTERNAL"}, {MCIERR_DRIVER, "MCIERR_DRIVER"},
    {MCIERR_CANNOT_USE_ALL, "MCIERR_CANNOT_USE_ALL"},
    {MCIERR_MULTIPLE, "MCIERR_MULTIPLE"},
    {MCIERR_EXTENSION_NOT_FOUND, "MCIERR_EXTENSION_NOT_FOUND"},
    {MCIERR_OUTOFRANGE, "MCIERR_OUTOFRANGE"},
    {MCIERR_FLAGS_NOT_COMPATIBLE, "MCIERR_FLAGS_NOT_COMPATIBLE"},
    {MCIERR_FILE_NOT_SAVED, "MCIERR_FILE_NOT_SAVED"},
    {MCIERR_DEVICE_TYPE_REQUIRED, "MCIERR_DEVICE_TYPE_REQUIRED"},
    {MCIERR_DEVICE_LOCKED, "MCIERR_DEVICE_LOCKED"},
    {MCIERR_DUPLICATE_ALIAS, "MCIERR_DUPLICATE_ALIAS"},
    {MCIERR_BAD_CONSTANT, "MCIERR_BAD_CONSTANT"},
    {MCIERR_MUST_USE_SHAREABLE, "MCIERR_MUST_USE_SHAREABLE"},
    {MCIERR_MISSING_DEVICE_NAME, "MCIERR_MISSING_DEVICE_NAME"},
    {MCIERR_BAD_TIME_FORMAT, "MCIERR_BAD_TIME_FORMAT"},
    {MCIERR_NO_CLOSING_QUOTE, "MCIERR_NO_CLOSING_QUOTE"},
    {MCIERR_DUPLICATE_FLAGS, "MCIERR_DUPLICATE_FLAGS"},
    {MCIERR_INVALID_FILE, "MCIERR_INVALID_FILE"},
    {MCIERR_NULL_PARAMETER_BLOCK, "MCIERR_NULL_PARAMETER_BLOCK"},
    {MCIERR_UNNAMED_RESOURCE, "MCIERR_UNNAMED_RESOURCE"},
    {MCIERR_NEW_REQUIRES_ALIAS, "MCIERR_NEW_REQUIRES_ALIAS"},
    {MCIERR_NOTIFY_ON_AUTO_OPEN, "MCIERR_NOTIFY_ON_AUTO_OPEN"},
    {MCIERR_NO_ELEMENT_ALLOWED, "MCIERR_NO_ELEMENT_ALLOWED"},
    {MCIERR_NONAPPLICABLE_FUNCTION, "MCIERR_NONAPPLICABLE_FUNCTION"},
    {MCIERR_ILLEGAL_FOR_AUTO_OPEN, "MCIERR_ILLEGAL_FOR_AUTO_OPEN"},
    {MCIERR_FILENAME_REQUIRED, "MCIERR_FILENAME_REQUIRED"},
    {MCIERR_EXTRA_CHARACTERS, "MCIERR_EXTRA_CHARACTERS"},
    {MCIERR_DEVICE_NOT_INSTALLED, "MCIERR_DEVICE_NOT_INSTALLED"},
    {MCIERR_GET_CD, "MCIERR_GET_CD"}, {MCIERR_SET_CD, "MCIERR_SET_CD"},
    {MCIERR_SET_DRIVE, "MCIERR_SET_DRIVE"},
    {MCIERR_DEVICE_LENGTH, "MCIERR_DEVICE_LENGTH"},
    {MCIERR_DEVICE_ORD_LENGTH, "MCIERR_DEVICE_ORD_LENGTH"},
    {MCIERR_NO_INTEGER, "MCIERR_NO_INTEGER"},
    {MCIERR_WAVE_OUTPUTSINUSE, "MCIERR_WAVE_OUTPUTSINUSE"},
    {MCIERR_WAVE_SETOUTPUTINUSE, "MCIERR_WAVE_SETOUTPUTINUSE"},
    {MCIERR_WAVE_INPUTSINUSE, "MCIERR_WAVE_INPUTSINUSE"},
    {MCIERR_WAVE_SETINPUTINUSE, "MCIERR_WAVE_SETINPUTINUSE"},
    {MCIERR_WAVE_OUTPUTUNSPECIFIED, "MCIERR_WAVE_OUTPUTUNSPECIFIED"},
    {MCIERR_WAVE_INPUTUNSPECIFIED, "MCIERR_WAVE_INPUTUNSPECIFIED"},
    {MCIERR_WAVE_OUTPUTSUNSUITABLE, "MCIERR_WAVE_OUTPUTSUNSUITABLE"},
    {MCIERR_WAVE_SETOUTPUTUNSUITABLE, "MCIERR_WAVE_SETOUTPUTUNSUITABLE"},
    {MCIERR_WAVE_INPUTSUNSUITABLE, "MCIERR_WAVE_INPUTSUNSUITABLE"},
    {MCIERR_WAVE_SETINPUTUNSUITABLE, "MCIERR_WAVE_SETINPUTUNSUITABLE"},
    {MCIERR_SEQ_DIV_INCOMPATIBLE, "MCIERR_SEQ_DIV_INCOMPATIBLE"},
    {MCIERR_SEQ_PORT_INUSE, "MCIERR_SEQ_PORT_INUSE"},
    {MCIERR_SEQ_PORT_NONEXISTENT, "MCIERR_SEQ_PORT_NONEXISTENT"},
    {MCIERR_SEQ_PORT_MAPNODEVICE, "MCIERR_SEQ_PORT_MAPNODEVICE"},
    {MCIERR_SEQ_PORT_MISCERROR, "MCIERR_SEQ_PORT_MISCERROR"},
    {MCIERR_SEQ_TIMER, "MCIERR_SEQ_TIMER"},
    {MCIERR_SEQ_PORTUNSPECIFIED, "MCIERR_SEQ_PORTUNSPECIFIED"},
    {MCIERR_SEQ_NOMIDIPRESENT, "MCIERR_SEQ_NOMIDIPRESENT"},
    {MCIERR_NO_WINDOW, "MCIERR_NO_WINDOW"},
    {MCIERR_CREATEWINDOW, "MCIERR_CREATEWINDOW"},
    {MCIERR_FILE_READ, "MCIERR_FILE_READ"},
    {MCIERR_FILE_WRITE, "MCIERR_FILE_WRITE"},
    {MCIERR_NO_IDENTITY, "MCIERR_NO_IDENTITY"}};

WinMMError::WinMMError(int32_t errorCode)
    : std::runtime_error("MCI error code")
    , m_errorCode(errorCode)
{
}

WinMMError::WinMMError(const char* message, int32_t errorCode)
    : std::runtime_error(message)
    , m_errorCode(errorCode)
{
}

WinMMError::WinMMError(const std::string& message, int32_t errorCode)
    : WinMMError(message.c_str(), errorCode)
{
}

int32_t WinMMError::getErrorCode() const
{
    return m_errorCode;
}

const std::string& WinMMError::getErrorName() const
{
    return MCIERR_NAMES[m_errorCode];
}
/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: C:\Users\tstro\Documents\PlatformIO\Projects\ARVP_Intro_project\lib\libuavcan\libuavcan\dsdl\uavcan\protocol\file\EntryType.uavcan
 */

#ifndef UAVCAN_PROTOCOL_FILE_ENTRYTYPE_HPP_INCLUDED
#define UAVCAN_PROTOCOL_FILE_ENTRYTYPE_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# Nested type.
# Represents the type of the file system entry (e.g. file or directory).
# If such entry does not exist, 'flags' must be set to zero.
#

uint8 FLAG_FILE      = 1        # Excludes FLAG_DIRECTORY
uint8 FLAG_DIRECTORY = 2        # Excludes FLAG_FILE
uint8 FLAG_SYMLINK   = 4        # Link target is either FLAG_FILE or FLAG_DIRECTORY
uint8 FLAG_READABLE  = 8
uint8 FLAG_WRITEABLE = 16

uint8 flags
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.file.EntryType
saturated uint8 flags
******************************************************************************/

#undef flags
#undef FLAG_FILE
#undef FLAG_DIRECTORY
#undef FLAG_SYMLINK
#undef FLAG_READABLE
#undef FLAG_WRITEABLE

namespace uavcan
{
namespace protocol
{
namespace file
{

template <int _tmpl>
struct UAVCAN_EXPORT EntryType_
{
    typedef const EntryType_<_tmpl>& ParameterType;
    typedef EntryType_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > FLAG_FILE;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > FLAG_DIRECTORY;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > FLAG_SYMLINK;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > FLAG_READABLE;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > FLAG_WRITEABLE;
    };

    struct FieldTypes
    {
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > flags;
    };

    enum
    {
        MinBitLen
            = FieldTypes::flags::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::flags::MaxBitLen
    };

    // Constants
    static const typename ::uavcan::StorageType< typename ConstantTypes::FLAG_FILE >::Type FLAG_FILE; // 1
    static const typename ::uavcan::StorageType< typename ConstantTypes::FLAG_DIRECTORY >::Type FLAG_DIRECTORY; // 2
    static const typename ::uavcan::StorageType< typename ConstantTypes::FLAG_SYMLINK >::Type FLAG_SYMLINK; // 4
    static const typename ::uavcan::StorageType< typename ConstantTypes::FLAG_READABLE >::Type FLAG_READABLE; // 8
    static const typename ::uavcan::StorageType< typename ConstantTypes::FLAG_WRITEABLE >::Type FLAG_WRITEABLE; // 16

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::flags >::Type flags;

    EntryType_()
        : flags()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<8 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    // This type has no default data type ID

    static const char* getDataTypeFullName()
    {
        return "uavcan.protocol.file.EntryType";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool EntryType_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        flags == rhs.flags;
}

template <int _tmpl>
bool EntryType_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(flags, rhs.flags);
}

template <int _tmpl>
int EntryType_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::flags::encode(self.flags, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int EntryType_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::flags::decode(self.flags, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature EntryType_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x6924572FBB2086E5ULL);

    FieldTypes::flags::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

template <int _tmpl>
const typename ::uavcan::StorageType< typename EntryType_<_tmpl>::ConstantTypes::FLAG_FILE >::Type
    EntryType_<_tmpl>::FLAG_FILE = 1U; // 1

template <int _tmpl>
const typename ::uavcan::StorageType< typename EntryType_<_tmpl>::ConstantTypes::FLAG_DIRECTORY >::Type
    EntryType_<_tmpl>::FLAG_DIRECTORY = 2U; // 2

template <int _tmpl>
const typename ::uavcan::StorageType< typename EntryType_<_tmpl>::ConstantTypes::FLAG_SYMLINK >::Type
    EntryType_<_tmpl>::FLAG_SYMLINK = 4U; // 4

template <int _tmpl>
const typename ::uavcan::StorageType< typename EntryType_<_tmpl>::ConstantTypes::FLAG_READABLE >::Type
    EntryType_<_tmpl>::FLAG_READABLE = 8U; // 8

template <int _tmpl>
const typename ::uavcan::StorageType< typename EntryType_<_tmpl>::ConstantTypes::FLAG_WRITEABLE >::Type
    EntryType_<_tmpl>::FLAG_WRITEABLE = 16U; // 16

/*
 * Final typedef
 */
typedef EntryType_<0> EntryType;

// No default registration

} // Namespace file
} // Namespace protocol
} // Namespace uavcan

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::protocol::file::EntryType >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::protocol::file::EntryType::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::protocol::file::EntryType >::stream(Stream& s, ::uavcan::protocol::file::EntryType::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "flags: ";
    YamlStreamer< ::uavcan::protocol::file::EntryType::FieldTypes::flags >::stream(s, obj.flags, level + 1);
}

}

namespace uavcan
{
namespace protocol
{
namespace file
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::protocol::file::EntryType::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::protocol::file::EntryType >::stream(s, obj, 0);
    return s;
}

} // Namespace file
} // Namespace protocol
} // Namespace uavcan

#endif // UAVCAN_PROTOCOL_FILE_ENTRYTYPE_HPP_INCLUDED
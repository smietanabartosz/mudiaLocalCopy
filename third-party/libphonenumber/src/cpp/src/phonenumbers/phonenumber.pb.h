// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: phonenumber.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_phonenumber_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_phonenumber_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_phonenumber_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_phonenumber_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
namespace i18n {
namespace phonenumbers {
class PhoneNumber;
class PhoneNumberDefaultTypeInternal;
extern PhoneNumberDefaultTypeInternal _PhoneNumber_default_instance_;
}  // namespace phonenumbers
}  // namespace i18n
PROTOBUF_NAMESPACE_OPEN
template<> ::i18n::phonenumbers::PhoneNumber* Arena::CreateMaybeMessage<::i18n::phonenumbers::PhoneNumber>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace i18n {
namespace phonenumbers {

enum PhoneNumber_CountryCodeSource : int {
  PhoneNumber_CountryCodeSource_UNSPECIFIED = 0,
  PhoneNumber_CountryCodeSource_FROM_NUMBER_WITH_PLUS_SIGN = 1,
  PhoneNumber_CountryCodeSource_FROM_NUMBER_WITH_IDD = 5,
  PhoneNumber_CountryCodeSource_FROM_NUMBER_WITHOUT_PLUS_SIGN = 10,
  PhoneNumber_CountryCodeSource_FROM_DEFAULT_COUNTRY = 20
};
bool PhoneNumber_CountryCodeSource_IsValid(int value);
constexpr PhoneNumber_CountryCodeSource PhoneNumber_CountryCodeSource_CountryCodeSource_MIN = PhoneNumber_CountryCodeSource_UNSPECIFIED;
constexpr PhoneNumber_CountryCodeSource PhoneNumber_CountryCodeSource_CountryCodeSource_MAX = PhoneNumber_CountryCodeSource_FROM_DEFAULT_COUNTRY;
constexpr int PhoneNumber_CountryCodeSource_CountryCodeSource_ARRAYSIZE = PhoneNumber_CountryCodeSource_CountryCodeSource_MAX + 1;

const std::string& PhoneNumber_CountryCodeSource_Name(PhoneNumber_CountryCodeSource value);
template<typename T>
inline const std::string& PhoneNumber_CountryCodeSource_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PhoneNumber_CountryCodeSource>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PhoneNumber_CountryCodeSource_Name.");
  return PhoneNumber_CountryCodeSource_Name(static_cast<PhoneNumber_CountryCodeSource>(enum_t_value));
}
bool PhoneNumber_CountryCodeSource_Parse(
    const std::string& name, PhoneNumber_CountryCodeSource* value);
// ===================================================================

class PhoneNumber :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:i18n.phonenumbers.PhoneNumber) */ {
 public:
  PhoneNumber();
  virtual ~PhoneNumber();

  PhoneNumber(const PhoneNumber& from);
  PhoneNumber(PhoneNumber&& from) noexcept
    : PhoneNumber() {
    *this = ::std::move(from);
  }

  inline PhoneNumber& operator=(const PhoneNumber& from) {
    CopyFrom(from);
    return *this;
  }
  inline PhoneNumber& operator=(PhoneNumber&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const std::string& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline std::string* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const PhoneNumber& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PhoneNumber* internal_default_instance() {
    return reinterpret_cast<const PhoneNumber*>(
               &_PhoneNumber_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PhoneNumber& a, PhoneNumber& b) {
    a.Swap(&b);
  }
  inline void Swap(PhoneNumber* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PhoneNumber* New() const final {
    return CreateMaybeMessage<PhoneNumber>(nullptr);
  }

  PhoneNumber* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PhoneNumber>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)
    final;
  void CopyFrom(const PhoneNumber& from);
  void MergeFrom(const PhoneNumber& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(PhoneNumber* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "i18n.phonenumbers.PhoneNumber";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  typedef PhoneNumber_CountryCodeSource CountryCodeSource;
  static constexpr CountryCodeSource UNSPECIFIED =
    PhoneNumber_CountryCodeSource_UNSPECIFIED;
  static constexpr CountryCodeSource FROM_NUMBER_WITH_PLUS_SIGN =
    PhoneNumber_CountryCodeSource_FROM_NUMBER_WITH_PLUS_SIGN;
  static constexpr CountryCodeSource FROM_NUMBER_WITH_IDD =
    PhoneNumber_CountryCodeSource_FROM_NUMBER_WITH_IDD;
  static constexpr CountryCodeSource FROM_NUMBER_WITHOUT_PLUS_SIGN =
    PhoneNumber_CountryCodeSource_FROM_NUMBER_WITHOUT_PLUS_SIGN;
  static constexpr CountryCodeSource FROM_DEFAULT_COUNTRY =
    PhoneNumber_CountryCodeSource_FROM_DEFAULT_COUNTRY;
  static inline bool CountryCodeSource_IsValid(int value) {
    return PhoneNumber_CountryCodeSource_IsValid(value);
  }
  static constexpr CountryCodeSource CountryCodeSource_MIN =
    PhoneNumber_CountryCodeSource_CountryCodeSource_MIN;
  static constexpr CountryCodeSource CountryCodeSource_MAX =
    PhoneNumber_CountryCodeSource_CountryCodeSource_MAX;
  static constexpr int CountryCodeSource_ARRAYSIZE =
    PhoneNumber_CountryCodeSource_CountryCodeSource_ARRAYSIZE;
  template<typename T>
  static inline const std::string& CountryCodeSource_Name(T enum_t_value) {
    static_assert(::std::is_same<T, CountryCodeSource>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function CountryCodeSource_Name.");
    return PhoneNumber_CountryCodeSource_Name(enum_t_value);
  }
  static inline bool CountryCodeSource_Parse(const std::string& name,
      CountryCodeSource* value) {
    return PhoneNumber_CountryCodeSource_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kExtensionFieldNumber = 3,
    kRawInputFieldNumber = 5,
    kPreferredDomesticCarrierCodeFieldNumber = 7,
    kNationalNumberFieldNumber = 2,
    kCountryCodeFieldNumber = 1,
    kItalianLeadingZeroFieldNumber = 4,
    kCountryCodeSourceFieldNumber = 6,
    kNumberOfLeadingZerosFieldNumber = 8,
  };
  // optional string extension = 3;
  bool has_extension() const;
  private:
  bool _internal_has_extension() const;
  public:
  void clear_extension();
  const std::string& extension() const;
  void set_extension(const std::string& value);
  void set_extension(std::string&& value);
  void set_extension(const char* value);
  void set_extension(const char* value, size_t size);
  std::string* mutable_extension();
  std::string* release_extension();
  void set_allocated_extension(std::string* extension);
  private:
  const std::string& _internal_extension() const;
  void _internal_set_extension(const std::string& value);
  std::string* _internal_mutable_extension();
  public:

  // optional string raw_input = 5;
  bool has_raw_input() const;
  private:
  bool _internal_has_raw_input() const;
  public:
  void clear_raw_input();
  const std::string& raw_input() const;
  void set_raw_input(const std::string& value);
  void set_raw_input(std::string&& value);
  void set_raw_input(const char* value);
  void set_raw_input(const char* value, size_t size);
  std::string* mutable_raw_input();
  std::string* release_raw_input();
  void set_allocated_raw_input(std::string* raw_input);
  private:
  const std::string& _internal_raw_input() const;
  void _internal_set_raw_input(const std::string& value);
  std::string* _internal_mutable_raw_input();
  public:

  // optional string preferred_domestic_carrier_code = 7;
  bool has_preferred_domestic_carrier_code() const;
  private:
  bool _internal_has_preferred_domestic_carrier_code() const;
  public:
  void clear_preferred_domestic_carrier_code();
  const std::string& preferred_domestic_carrier_code() const;
  void set_preferred_domestic_carrier_code(const std::string& value);
  void set_preferred_domestic_carrier_code(std::string&& value);
  void set_preferred_domestic_carrier_code(const char* value);
  void set_preferred_domestic_carrier_code(const char* value, size_t size);
  std::string* mutable_preferred_domestic_carrier_code();
  std::string* release_preferred_domestic_carrier_code();
  void set_allocated_preferred_domestic_carrier_code(std::string* preferred_domestic_carrier_code);
  private:
  const std::string& _internal_preferred_domestic_carrier_code() const;
  void _internal_set_preferred_domestic_carrier_code(const std::string& value);
  std::string* _internal_mutable_preferred_domestic_carrier_code();
  public:

  // required uint64 national_number = 2;
  bool has_national_number() const;
  private:
  bool _internal_has_national_number() const;
  public:
  void clear_national_number();
  ::PROTOBUF_NAMESPACE_ID::uint64 national_number() const;
  void set_national_number(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_national_number() const;
  void _internal_set_national_number(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // required int32 country_code = 1;
  bool has_country_code() const;
  private:
  bool _internal_has_country_code() const;
  public:
  void clear_country_code();
  ::PROTOBUF_NAMESPACE_ID::int32 country_code() const;
  void set_country_code(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_country_code() const;
  void _internal_set_country_code(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // optional bool italian_leading_zero = 4;
  bool has_italian_leading_zero() const;
  private:
  bool _internal_has_italian_leading_zero() const;
  public:
  void clear_italian_leading_zero();
  bool italian_leading_zero() const;
  void set_italian_leading_zero(bool value);
  private:
  bool _internal_italian_leading_zero() const;
  void _internal_set_italian_leading_zero(bool value);
  public:

  // optional .i18n.phonenumbers.PhoneNumber.CountryCodeSource country_code_source = 6;
  bool has_country_code_source() const;
  private:
  bool _internal_has_country_code_source() const;
  public:
  void clear_country_code_source();
  ::i18n::phonenumbers::PhoneNumber_CountryCodeSource country_code_source() const;
  void set_country_code_source(::i18n::phonenumbers::PhoneNumber_CountryCodeSource value);
  private:
  ::i18n::phonenumbers::PhoneNumber_CountryCodeSource _internal_country_code_source() const;
  void _internal_set_country_code_source(::i18n::phonenumbers::PhoneNumber_CountryCodeSource value);
  public:

  // optional int32 number_of_leading_zeros = 8 [default = 1];
  bool has_number_of_leading_zeros() const;
  private:
  bool _internal_has_number_of_leading_zeros() const;
  public:
  void clear_number_of_leading_zeros();
  ::PROTOBUF_NAMESPACE_ID::int32 number_of_leading_zeros() const;
  void set_number_of_leading_zeros(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_number_of_leading_zeros() const;
  void _internal_set_number_of_leading_zeros(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:i18n.phonenumbers.PhoneNumber)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr extension_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr raw_input_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr preferred_domestic_carrier_code_;
  ::PROTOBUF_NAMESPACE_ID::uint64 national_number_;
  ::PROTOBUF_NAMESPACE_ID::int32 country_code_;
  bool italian_leading_zero_;
  int country_code_source_;
  ::PROTOBUF_NAMESPACE_ID::int32 number_of_leading_zeros_;
  friend struct ::TableStruct_phonenumber_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PhoneNumber

// required int32 country_code = 1;
inline bool PhoneNumber::_internal_has_country_code() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool PhoneNumber::has_country_code() const {
  return _internal_has_country_code();
}
inline void PhoneNumber::clear_country_code() {
  country_code_ = 0;
  _has_bits_[0] &= ~0x00000010u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 PhoneNumber::_internal_country_code() const {
  return country_code_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 PhoneNumber::country_code() const {
  // @@protoc_insertion_point(field_get:i18n.phonenumbers.PhoneNumber.country_code)
  return _internal_country_code();
}
inline void PhoneNumber::_internal_set_country_code(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000010u;
  country_code_ = value;
}
inline void PhoneNumber::set_country_code(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_country_code(value);
  // @@protoc_insertion_point(field_set:i18n.phonenumbers.PhoneNumber.country_code)
}

// required uint64 national_number = 2;
inline bool PhoneNumber::_internal_has_national_number() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool PhoneNumber::has_national_number() const {
  return _internal_has_national_number();
}
inline void PhoneNumber::clear_national_number() {
  national_number_ = PROTOBUF_ULONGLONG(0);
  _has_bits_[0] &= ~0x00000008u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 PhoneNumber::_internal_national_number() const {
  return national_number_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 PhoneNumber::national_number() const {
  // @@protoc_insertion_point(field_get:i18n.phonenumbers.PhoneNumber.national_number)
  return _internal_national_number();
}
inline void PhoneNumber::_internal_set_national_number(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _has_bits_[0] |= 0x00000008u;
  national_number_ = value;
}
inline void PhoneNumber::set_national_number(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_national_number(value);
  // @@protoc_insertion_point(field_set:i18n.phonenumbers.PhoneNumber.national_number)
}

// optional string extension = 3;
inline bool PhoneNumber::_internal_has_extension() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool PhoneNumber::has_extension() const {
  return _internal_has_extension();
}
inline void PhoneNumber::clear_extension() {
  extension_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& PhoneNumber::extension() const {
  // @@protoc_insertion_point(field_get:i18n.phonenumbers.PhoneNumber.extension)
  return _internal_extension();
}
inline void PhoneNumber::set_extension(const std::string& value) {
  _internal_set_extension(value);
  // @@protoc_insertion_point(field_set:i18n.phonenumbers.PhoneNumber.extension)
}
inline std::string* PhoneNumber::mutable_extension() {
  // @@protoc_insertion_point(field_mutable:i18n.phonenumbers.PhoneNumber.extension)
  return _internal_mutable_extension();
}
inline const std::string& PhoneNumber::_internal_extension() const {
  return extension_.GetNoArena();
}
inline void PhoneNumber::_internal_set_extension(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  extension_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void PhoneNumber::set_extension(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  extension_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:i18n.phonenumbers.PhoneNumber.extension)
}
inline void PhoneNumber::set_extension(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  extension_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:i18n.phonenumbers.PhoneNumber.extension)
}
inline void PhoneNumber::set_extension(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  extension_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:i18n.phonenumbers.PhoneNumber.extension)
}
inline std::string* PhoneNumber::_internal_mutable_extension() {
  _has_bits_[0] |= 0x00000001u;
  return extension_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* PhoneNumber::release_extension() {
  // @@protoc_insertion_point(field_release:i18n.phonenumbers.PhoneNumber.extension)
  if (!_internal_has_extension()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return extension_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void PhoneNumber::set_allocated_extension(std::string* extension) {
  if (extension != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  extension_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), extension);
  // @@protoc_insertion_point(field_set_allocated:i18n.phonenumbers.PhoneNumber.extension)
}

// optional bool italian_leading_zero = 4;
inline bool PhoneNumber::_internal_has_italian_leading_zero() const {
  bool value = (_has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool PhoneNumber::has_italian_leading_zero() const {
  return _internal_has_italian_leading_zero();
}
inline void PhoneNumber::clear_italian_leading_zero() {
  italian_leading_zero_ = false;
  _has_bits_[0] &= ~0x00000020u;
}
inline bool PhoneNumber::_internal_italian_leading_zero() const {
  return italian_leading_zero_;
}
inline bool PhoneNumber::italian_leading_zero() const {
  // @@protoc_insertion_point(field_get:i18n.phonenumbers.PhoneNumber.italian_leading_zero)
  return _internal_italian_leading_zero();
}
inline void PhoneNumber::_internal_set_italian_leading_zero(bool value) {
  _has_bits_[0] |= 0x00000020u;
  italian_leading_zero_ = value;
}
inline void PhoneNumber::set_italian_leading_zero(bool value) {
  _internal_set_italian_leading_zero(value);
  // @@protoc_insertion_point(field_set:i18n.phonenumbers.PhoneNumber.italian_leading_zero)
}

// optional int32 number_of_leading_zeros = 8 [default = 1];
inline bool PhoneNumber::_internal_has_number_of_leading_zeros() const {
  bool value = (_has_bits_[0] & 0x00000080u) != 0;
  return value;
}
inline bool PhoneNumber::has_number_of_leading_zeros() const {
  return _internal_has_number_of_leading_zeros();
}
inline void PhoneNumber::clear_number_of_leading_zeros() {
  number_of_leading_zeros_ = 1;
  _has_bits_[0] &= ~0x00000080u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 PhoneNumber::_internal_number_of_leading_zeros() const {
  return number_of_leading_zeros_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 PhoneNumber::number_of_leading_zeros() const {
  // @@protoc_insertion_point(field_get:i18n.phonenumbers.PhoneNumber.number_of_leading_zeros)
  return _internal_number_of_leading_zeros();
}
inline void PhoneNumber::_internal_set_number_of_leading_zeros(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000080u;
  number_of_leading_zeros_ = value;
}
inline void PhoneNumber::set_number_of_leading_zeros(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_number_of_leading_zeros(value);
  // @@protoc_insertion_point(field_set:i18n.phonenumbers.PhoneNumber.number_of_leading_zeros)
}

// optional string raw_input = 5;
inline bool PhoneNumber::_internal_has_raw_input() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool PhoneNumber::has_raw_input() const {
  return _internal_has_raw_input();
}
inline void PhoneNumber::clear_raw_input() {
  raw_input_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& PhoneNumber::raw_input() const {
  // @@protoc_insertion_point(field_get:i18n.phonenumbers.PhoneNumber.raw_input)
  return _internal_raw_input();
}
inline void PhoneNumber::set_raw_input(const std::string& value) {
  _internal_set_raw_input(value);
  // @@protoc_insertion_point(field_set:i18n.phonenumbers.PhoneNumber.raw_input)
}
inline std::string* PhoneNumber::mutable_raw_input() {
  // @@protoc_insertion_point(field_mutable:i18n.phonenumbers.PhoneNumber.raw_input)
  return _internal_mutable_raw_input();
}
inline const std::string& PhoneNumber::_internal_raw_input() const {
  return raw_input_.GetNoArena();
}
inline void PhoneNumber::_internal_set_raw_input(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  raw_input_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void PhoneNumber::set_raw_input(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  raw_input_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:i18n.phonenumbers.PhoneNumber.raw_input)
}
inline void PhoneNumber::set_raw_input(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  raw_input_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:i18n.phonenumbers.PhoneNumber.raw_input)
}
inline void PhoneNumber::set_raw_input(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  raw_input_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:i18n.phonenumbers.PhoneNumber.raw_input)
}
inline std::string* PhoneNumber::_internal_mutable_raw_input() {
  _has_bits_[0] |= 0x00000002u;
  return raw_input_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* PhoneNumber::release_raw_input() {
  // @@protoc_insertion_point(field_release:i18n.phonenumbers.PhoneNumber.raw_input)
  if (!_internal_has_raw_input()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return raw_input_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void PhoneNumber::set_allocated_raw_input(std::string* raw_input) {
  if (raw_input != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  raw_input_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), raw_input);
  // @@protoc_insertion_point(field_set_allocated:i18n.phonenumbers.PhoneNumber.raw_input)
}

// optional .i18n.phonenumbers.PhoneNumber.CountryCodeSource country_code_source = 6;
inline bool PhoneNumber::_internal_has_country_code_source() const {
  bool value = (_has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool PhoneNumber::has_country_code_source() const {
  return _internal_has_country_code_source();
}
inline void PhoneNumber::clear_country_code_source() {
  country_code_source_ = 0;
  _has_bits_[0] &= ~0x00000040u;
}
inline ::i18n::phonenumbers::PhoneNumber_CountryCodeSource PhoneNumber::_internal_country_code_source() const {
  return static_cast< ::i18n::phonenumbers::PhoneNumber_CountryCodeSource >(country_code_source_);
}
inline ::i18n::phonenumbers::PhoneNumber_CountryCodeSource PhoneNumber::country_code_source() const {
  // @@protoc_insertion_point(field_get:i18n.phonenumbers.PhoneNumber.country_code_source)
  return _internal_country_code_source();
}
inline void PhoneNumber::_internal_set_country_code_source(::i18n::phonenumbers::PhoneNumber_CountryCodeSource value) {
  assert(::i18n::phonenumbers::PhoneNumber_CountryCodeSource_IsValid(value));
  _has_bits_[0] |= 0x00000040u;
  country_code_source_ = value;
}
inline void PhoneNumber::set_country_code_source(::i18n::phonenumbers::PhoneNumber_CountryCodeSource value) {
  _internal_set_country_code_source(value);
  // @@protoc_insertion_point(field_set:i18n.phonenumbers.PhoneNumber.country_code_source)
}

// optional string preferred_domestic_carrier_code = 7;
inline bool PhoneNumber::_internal_has_preferred_domestic_carrier_code() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool PhoneNumber::has_preferred_domestic_carrier_code() const {
  return _internal_has_preferred_domestic_carrier_code();
}
inline void PhoneNumber::clear_preferred_domestic_carrier_code() {
  preferred_domestic_carrier_code_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000004u;
}
inline const std::string& PhoneNumber::preferred_domestic_carrier_code() const {
  // @@protoc_insertion_point(field_get:i18n.phonenumbers.PhoneNumber.preferred_domestic_carrier_code)
  return _internal_preferred_domestic_carrier_code();
}
inline void PhoneNumber::set_preferred_domestic_carrier_code(const std::string& value) {
  _internal_set_preferred_domestic_carrier_code(value);
  // @@protoc_insertion_point(field_set:i18n.phonenumbers.PhoneNumber.preferred_domestic_carrier_code)
}
inline std::string* PhoneNumber::mutable_preferred_domestic_carrier_code() {
  // @@protoc_insertion_point(field_mutable:i18n.phonenumbers.PhoneNumber.preferred_domestic_carrier_code)
  return _internal_mutable_preferred_domestic_carrier_code();
}
inline const std::string& PhoneNumber::_internal_preferred_domestic_carrier_code() const {
  return preferred_domestic_carrier_code_.GetNoArena();
}
inline void PhoneNumber::_internal_set_preferred_domestic_carrier_code(const std::string& value) {
  _has_bits_[0] |= 0x00000004u;
  preferred_domestic_carrier_code_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void PhoneNumber::set_preferred_domestic_carrier_code(std::string&& value) {
  _has_bits_[0] |= 0x00000004u;
  preferred_domestic_carrier_code_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:i18n.phonenumbers.PhoneNumber.preferred_domestic_carrier_code)
}
inline void PhoneNumber::set_preferred_domestic_carrier_code(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000004u;
  preferred_domestic_carrier_code_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:i18n.phonenumbers.PhoneNumber.preferred_domestic_carrier_code)
}
inline void PhoneNumber::set_preferred_domestic_carrier_code(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000004u;
  preferred_domestic_carrier_code_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:i18n.phonenumbers.PhoneNumber.preferred_domestic_carrier_code)
}
inline std::string* PhoneNumber::_internal_mutable_preferred_domestic_carrier_code() {
  _has_bits_[0] |= 0x00000004u;
  return preferred_domestic_carrier_code_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* PhoneNumber::release_preferred_domestic_carrier_code() {
  // @@protoc_insertion_point(field_release:i18n.phonenumbers.PhoneNumber.preferred_domestic_carrier_code)
  if (!_internal_has_preferred_domestic_carrier_code()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000004u;
  return preferred_domestic_carrier_code_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void PhoneNumber::set_allocated_preferred_domestic_carrier_code(std::string* preferred_domestic_carrier_code) {
  if (preferred_domestic_carrier_code != nullptr) {
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  preferred_domestic_carrier_code_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), preferred_domestic_carrier_code);
  // @@protoc_insertion_point(field_set_allocated:i18n.phonenumbers.PhoneNumber.preferred_domestic_carrier_code)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace phonenumbers
}  // namespace i18n

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::i18n::phonenumbers::PhoneNumber_CountryCodeSource> : ::std::true_type {};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_phonenumber_2eproto

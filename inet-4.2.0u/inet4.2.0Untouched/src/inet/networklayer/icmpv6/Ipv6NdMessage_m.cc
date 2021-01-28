//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/icmpv6/Ipv6NdMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include "Ipv6NdMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Ipv6NdOptionTypes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Ipv6NdOptionTypes"));
    e->insert(IPv6ND_SOURCE_LINK_LAYER_ADDR_OPTION, "IPv6ND_SOURCE_LINK_LAYER_ADDR_OPTION");
    e->insert(IPv6ND_TARGET_LINK_LAYER_ADDR_OPTION, "IPv6ND_TARGET_LINK_LAYER_ADDR_OPTION");
    e->insert(IPv6ND_PREFIX_INFORMATION, "IPv6ND_PREFIX_INFORMATION");
    e->insert(IPv6ND_REDIRECTED_HEADER, "IPv6ND_REDIRECTED_HEADER");
    e->insert(IPv6ND_MTU, "IPv6ND_MTU");
    e->insert(IPv6ND_ADVERTISEMENT_INTERVAL, "IPv6ND_ADVERTISEMENT_INTERVAL");
    e->insert(IPv6ND_HOME_AGENT_INFORMATION_OPTION, "IPv6ND_HOME_AGENT_INFORMATION_OPTION");
)

Register_Class(Ipv6NdOption)

Ipv6NdOption::Ipv6NdOption() : ::omnetpp::cObject()
{
}

Ipv6NdOption::Ipv6NdOption(const Ipv6NdOption& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ipv6NdOption::~Ipv6NdOption()
{
    delete [] this->paddingBytes;
}

Ipv6NdOption& Ipv6NdOption::operator=(const Ipv6NdOption& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NdOption::copy(const Ipv6NdOption& other)
{
    this->type = other.type;
    this->optionLength = other.optionLength;
    delete [] this->paddingBytes;
    this->paddingBytes = (other.paddingBytes_arraysize==0) ? nullptr : new char[other.paddingBytes_arraysize];
    paddingBytes_arraysize = other.paddingBytes_arraysize;
    for (size_t i = 0; i < paddingBytes_arraysize; i++) {
        this->paddingBytes[i] = other.paddingBytes[i];
    }
}

void Ipv6NdOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->optionLength);
    b->pack(paddingBytes_arraysize);
    doParsimArrayPacking(b,this->paddingBytes,paddingBytes_arraysize);
}

void Ipv6NdOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->optionLength);
    delete [] this->paddingBytes;
    b->unpack(paddingBytes_arraysize);
    if (paddingBytes_arraysize == 0) {
        this->paddingBytes = nullptr;
    } else {
        this->paddingBytes = new char[paddingBytes_arraysize];
        doParsimArrayUnpacking(b,this->paddingBytes,paddingBytes_arraysize);
    }
}

inet::Ipv6NdOptionTypes Ipv6NdOption::getType() const
{
    return this->type;
}

void Ipv6NdOption::setType(inet::Ipv6NdOptionTypes type)
{
    this->type = type;
}

short Ipv6NdOption::getOptionLength() const
{
    return this->optionLength;
}

void Ipv6NdOption::setOptionLength(short optionLength)
{
    this->optionLength = optionLength;
}

size_t Ipv6NdOption::getPaddingBytesArraySize() const
{
    return paddingBytes_arraysize;
}

char Ipv6NdOption::getPaddingBytes(size_t k) const
{
    if (k >= paddingBytes_arraysize) throw omnetpp::cRuntimeError("Array of size paddingBytes_arraysize indexed by %lu", (unsigned long)k);
    return this->paddingBytes[k];
}

void Ipv6NdOption::setPaddingBytesArraySize(size_t newSize)
{
    char *paddingBytes2 = (newSize==0) ? nullptr : new char[newSize];
    size_t minSize = paddingBytes_arraysize < newSize ? paddingBytes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        paddingBytes2[i] = this->paddingBytes[i];
    for (size_t i = minSize; i < newSize; i++)
        paddingBytes2[i] = 0;
    delete [] this->paddingBytes;
    this->paddingBytes = paddingBytes2;
    paddingBytes_arraysize = newSize;
}

void Ipv6NdOption::setPaddingBytes(size_t k, char paddingBytes)
{
    if (k >= paddingBytes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->paddingBytes[k] = paddingBytes;
}

void Ipv6NdOption::insertPaddingBytes(size_t k, char paddingBytes)
{
    if (k > paddingBytes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = paddingBytes_arraysize + 1;
    char *paddingBytes2 = new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        paddingBytes2[i] = this->paddingBytes[i];
    paddingBytes2[k] = paddingBytes;
    for (i = k + 1; i < newSize; i++)
        paddingBytes2[i] = this->paddingBytes[i-1];
    delete [] this->paddingBytes;
    this->paddingBytes = paddingBytes2;
    paddingBytes_arraysize = newSize;
}

void Ipv6NdOption::insertPaddingBytes(char paddingBytes)
{
    insertPaddingBytes(paddingBytes_arraysize, paddingBytes);
}

void Ipv6NdOption::erasePaddingBytes(size_t k)
{
    if (k >= paddingBytes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = paddingBytes_arraysize - 1;
    char *paddingBytes2 = (newSize == 0) ? nullptr : new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        paddingBytes2[i] = this->paddingBytes[i];
    for (i = k; i < newSize; i++)
        paddingBytes2[i] = this->paddingBytes[i+1];
    delete [] this->paddingBytes;
    this->paddingBytes = paddingBytes2;
    paddingBytes_arraysize = newSize;
}

class Ipv6NdOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_optionLength,
        FIELD_paddingBytes,
    };
  public:
    Ipv6NdOptionDescriptor();
    virtual ~Ipv6NdOptionDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NdOptionDescriptor)

Ipv6NdOptionDescriptor::Ipv6NdOptionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NdOption)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ipv6NdOptionDescriptor::~Ipv6NdOptionDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NdOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NdOption *>(obj)!=nullptr;
}

const char **Ipv6NdOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NdOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NdOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ipv6NdOptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_optionLength
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_paddingBytes
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6NdOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "optionLength",
        "paddingBytes",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ipv6NdOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "optionLength") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "paddingBytes") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NdOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv6NdOptionTypes",    // FIELD_type
        "short",    // FIELD_optionLength
        "char",    // FIELD_paddingBytes
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6NdOptionDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ipv6NdOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::Ipv6NdOptionTypes";
            return nullptr;
        default: return nullptr;
    }
}

int Ipv6NdOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdOption *pp = (Ipv6NdOption *)object; (void)pp;
    switch (field) {
        case FIELD_paddingBytes: return pp->getPaddingBytesArraySize();
        default: return 0;
    }
}

const char *Ipv6NdOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdOption *pp = (Ipv6NdOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6NdOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdOption *pp = (Ipv6NdOption *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::Ipv6NdOptionTypes");
        case FIELD_optionLength: return long2string(pp->getOptionLength());
        case FIELD_paddingBytes: return long2string(pp->getPaddingBytes(i));
        default: return "";
    }
}

bool Ipv6NdOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdOption *pp = (Ipv6NdOption *)object; (void)pp;
    switch (field) {
        case FIELD_optionLength: pp->setOptionLength(string2long(value)); return true;
        case FIELD_paddingBytes: pp->setPaddingBytes(i,string2long(value)); return true;
        default: return false;
    }
}

const char *Ipv6NdOptionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ipv6NdOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdOption *pp = (Ipv6NdOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv6NdSourceTargetLinkLayerAddress)

Ipv6NdSourceTargetLinkLayerAddress::Ipv6NdSourceTargetLinkLayerAddress() : ::inet::Ipv6NdOption()
{
    this->setOptionLength(1);

}

Ipv6NdSourceTargetLinkLayerAddress::Ipv6NdSourceTargetLinkLayerAddress(const Ipv6NdSourceTargetLinkLayerAddress& other) : ::inet::Ipv6NdOption(other)
{
    copy(other);
}

Ipv6NdSourceTargetLinkLayerAddress::~Ipv6NdSourceTargetLinkLayerAddress()
{
}

Ipv6NdSourceTargetLinkLayerAddress& Ipv6NdSourceTargetLinkLayerAddress::operator=(const Ipv6NdSourceTargetLinkLayerAddress& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdOption::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NdSourceTargetLinkLayerAddress::copy(const Ipv6NdSourceTargetLinkLayerAddress& other)
{
    this->linkLayerAddress = other.linkLayerAddress;
}

void Ipv6NdSourceTargetLinkLayerAddress::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdOption::parsimPack(b);
    doParsimPacking(b,this->linkLayerAddress);
}

void Ipv6NdSourceTargetLinkLayerAddress::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdOption::parsimUnpack(b);
    doParsimUnpacking(b,this->linkLayerAddress);
}

const MacAddress& Ipv6NdSourceTargetLinkLayerAddress::getLinkLayerAddress() const
{
    return this->linkLayerAddress;
}

void Ipv6NdSourceTargetLinkLayerAddress::setLinkLayerAddress(const MacAddress& linkLayerAddress)
{
    this->linkLayerAddress = linkLayerAddress;
}

class Ipv6NdSourceTargetLinkLayerAddressDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_linkLayerAddress,
    };
  public:
    Ipv6NdSourceTargetLinkLayerAddressDescriptor();
    virtual ~Ipv6NdSourceTargetLinkLayerAddressDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NdSourceTargetLinkLayerAddressDescriptor)

Ipv6NdSourceTargetLinkLayerAddressDescriptor::Ipv6NdSourceTargetLinkLayerAddressDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NdSourceTargetLinkLayerAddress)), "inet::Ipv6NdOption")
{
    propertynames = nullptr;
}

Ipv6NdSourceTargetLinkLayerAddressDescriptor::~Ipv6NdSourceTargetLinkLayerAddressDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NdSourceTargetLinkLayerAddressDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NdSourceTargetLinkLayerAddress *>(obj)!=nullptr;
}

const char **Ipv6NdSourceTargetLinkLayerAddressDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NdSourceTargetLinkLayerAddressDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_linkLayerAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "linkLayerAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ipv6NdSourceTargetLinkLayerAddressDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkLayerAddress") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_linkLayerAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdSourceTargetLinkLayerAddress *pp = (Ipv6NdSourceTargetLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdSourceTargetLinkLayerAddress *pp = (Ipv6NdSourceTargetLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdSourceTargetLinkLayerAddress *pp = (Ipv6NdSourceTargetLinkLayerAddress *)object; (void)pp;
    switch (field) {
        case FIELD_linkLayerAddress: return pp->getLinkLayerAddress().str();
        default: return "";
    }
}

bool Ipv6NdSourceTargetLinkLayerAddressDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdSourceTargetLinkLayerAddress *pp = (Ipv6NdSourceTargetLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ipv6NdSourceTargetLinkLayerAddressDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdSourceTargetLinkLayerAddress *pp = (Ipv6NdSourceTargetLinkLayerAddress *)object; (void)pp;
    switch (field) {
        case FIELD_linkLayerAddress: return toVoidPtr(&pp->getLinkLayerAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6NdSourceLinkLayerAddress)

Ipv6NdSourceLinkLayerAddress::Ipv6NdSourceLinkLayerAddress() : ::inet::Ipv6NdSourceTargetLinkLayerAddress()
{
    this->setType(IPv6ND_SOURCE_LINK_LAYER_ADDR_OPTION);
}

Ipv6NdSourceLinkLayerAddress::Ipv6NdSourceLinkLayerAddress(const Ipv6NdSourceLinkLayerAddress& other) : ::inet::Ipv6NdSourceTargetLinkLayerAddress(other)
{
    copy(other);
}

Ipv6NdSourceLinkLayerAddress::~Ipv6NdSourceLinkLayerAddress()
{
}

Ipv6NdSourceLinkLayerAddress& Ipv6NdSourceLinkLayerAddress::operator=(const Ipv6NdSourceLinkLayerAddress& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdSourceTargetLinkLayerAddress::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NdSourceLinkLayerAddress::copy(const Ipv6NdSourceLinkLayerAddress& other)
{
}

void Ipv6NdSourceLinkLayerAddress::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdSourceTargetLinkLayerAddress::parsimPack(b);
}

void Ipv6NdSourceLinkLayerAddress::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdSourceTargetLinkLayerAddress::parsimUnpack(b);
}

class Ipv6NdSourceLinkLayerAddressDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ipv6NdSourceLinkLayerAddressDescriptor();
    virtual ~Ipv6NdSourceLinkLayerAddressDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NdSourceLinkLayerAddressDescriptor)

Ipv6NdSourceLinkLayerAddressDescriptor::Ipv6NdSourceLinkLayerAddressDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NdSourceLinkLayerAddress)), "inet::Ipv6NdSourceTargetLinkLayerAddress")
{
    propertynames = nullptr;
}

Ipv6NdSourceLinkLayerAddressDescriptor::~Ipv6NdSourceLinkLayerAddressDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NdSourceLinkLayerAddressDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NdSourceLinkLayerAddress *>(obj)!=nullptr;
}

const char **Ipv6NdSourceLinkLayerAddressDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NdSourceLinkLayerAddressDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NdSourceLinkLayerAddressDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ipv6NdSourceLinkLayerAddressDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ipv6NdSourceLinkLayerAddressDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ipv6NdSourceLinkLayerAddressDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NdSourceLinkLayerAddressDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ipv6NdSourceLinkLayerAddressDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6NdSourceLinkLayerAddressDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6NdSourceLinkLayerAddressDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdSourceLinkLayerAddress *pp = (Ipv6NdSourceLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6NdSourceLinkLayerAddressDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdSourceLinkLayerAddress *pp = (Ipv6NdSourceLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6NdSourceLinkLayerAddressDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdSourceLinkLayerAddress *pp = (Ipv6NdSourceLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ipv6NdSourceLinkLayerAddressDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdSourceLinkLayerAddress *pp = (Ipv6NdSourceLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6NdSourceLinkLayerAddressDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ipv6NdSourceLinkLayerAddressDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdSourceLinkLayerAddress *pp = (Ipv6NdSourceLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv6NdTargetLinkLayerAddress)

Ipv6NdTargetLinkLayerAddress::Ipv6NdTargetLinkLayerAddress() : ::inet::Ipv6NdSourceTargetLinkLayerAddress()
{
    this->setType(IPv6ND_TARGET_LINK_LAYER_ADDR_OPTION);
}

Ipv6NdTargetLinkLayerAddress::Ipv6NdTargetLinkLayerAddress(const Ipv6NdTargetLinkLayerAddress& other) : ::inet::Ipv6NdSourceTargetLinkLayerAddress(other)
{
    copy(other);
}

Ipv6NdTargetLinkLayerAddress::~Ipv6NdTargetLinkLayerAddress()
{
}

Ipv6NdTargetLinkLayerAddress& Ipv6NdTargetLinkLayerAddress::operator=(const Ipv6NdTargetLinkLayerAddress& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdSourceTargetLinkLayerAddress::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NdTargetLinkLayerAddress::copy(const Ipv6NdTargetLinkLayerAddress& other)
{
}

void Ipv6NdTargetLinkLayerAddress::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdSourceTargetLinkLayerAddress::parsimPack(b);
}

void Ipv6NdTargetLinkLayerAddress::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdSourceTargetLinkLayerAddress::parsimUnpack(b);
}

class Ipv6NdTargetLinkLayerAddressDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ipv6NdTargetLinkLayerAddressDescriptor();
    virtual ~Ipv6NdTargetLinkLayerAddressDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NdTargetLinkLayerAddressDescriptor)

Ipv6NdTargetLinkLayerAddressDescriptor::Ipv6NdTargetLinkLayerAddressDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NdTargetLinkLayerAddress)), "inet::Ipv6NdSourceTargetLinkLayerAddress")
{
    propertynames = nullptr;
}

Ipv6NdTargetLinkLayerAddressDescriptor::~Ipv6NdTargetLinkLayerAddressDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NdTargetLinkLayerAddressDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NdTargetLinkLayerAddress *>(obj)!=nullptr;
}

const char **Ipv6NdTargetLinkLayerAddressDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NdTargetLinkLayerAddressDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NdTargetLinkLayerAddressDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ipv6NdTargetLinkLayerAddressDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ipv6NdTargetLinkLayerAddressDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ipv6NdTargetLinkLayerAddressDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NdTargetLinkLayerAddressDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ipv6NdTargetLinkLayerAddressDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6NdTargetLinkLayerAddressDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6NdTargetLinkLayerAddressDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdTargetLinkLayerAddress *pp = (Ipv6NdTargetLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6NdTargetLinkLayerAddressDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdTargetLinkLayerAddress *pp = (Ipv6NdTargetLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6NdTargetLinkLayerAddressDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdTargetLinkLayerAddress *pp = (Ipv6NdTargetLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ipv6NdTargetLinkLayerAddressDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdTargetLinkLayerAddress *pp = (Ipv6NdTargetLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6NdTargetLinkLayerAddressDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ipv6NdTargetLinkLayerAddressDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdTargetLinkLayerAddress *pp = (Ipv6NdTargetLinkLayerAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv6NdPrefixInformation)

Ipv6NdPrefixInformation::Ipv6NdPrefixInformation() : ::inet::Ipv6NdOption()
{
    this->setType(IPv6ND_PREFIX_INFORMATION);
    this->setOptionLength(4);

}

Ipv6NdPrefixInformation::Ipv6NdPrefixInformation(const Ipv6NdPrefixInformation& other) : ::inet::Ipv6NdOption(other)
{
    copy(other);
}

Ipv6NdPrefixInformation::~Ipv6NdPrefixInformation()
{
}

Ipv6NdPrefixInformation& Ipv6NdPrefixInformation::operator=(const Ipv6NdPrefixInformation& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdOption::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NdPrefixInformation::copy(const Ipv6NdPrefixInformation& other)
{
    this->prefixLength = other.prefixLength;
    this->onlinkFlag = other.onlinkFlag;
    this->autoAddressConfFlag = other.autoAddressConfFlag;
    this->routerAddressFlag = other.routerAddressFlag;
    this->reserved1 = other.reserved1;
    this->validLifetime = other.validLifetime;
    this->preferredLifetime = other.preferredLifetime;
    this->reserved2 = other.reserved2;
    this->prefix = other.prefix;
}

void Ipv6NdPrefixInformation::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdOption::parsimPack(b);
    doParsimPacking(b,this->prefixLength);
    doParsimPacking(b,this->onlinkFlag);
    doParsimPacking(b,this->autoAddressConfFlag);
    doParsimPacking(b,this->routerAddressFlag);
    doParsimPacking(b,this->reserved1);
    doParsimPacking(b,this->validLifetime);
    doParsimPacking(b,this->preferredLifetime);
    doParsimPacking(b,this->reserved2);
    doParsimPacking(b,this->prefix);
}

void Ipv6NdPrefixInformation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdOption::parsimUnpack(b);
    doParsimUnpacking(b,this->prefixLength);
    doParsimUnpacking(b,this->onlinkFlag);
    doParsimUnpacking(b,this->autoAddressConfFlag);
    doParsimUnpacking(b,this->routerAddressFlag);
    doParsimUnpacking(b,this->reserved1);
    doParsimUnpacking(b,this->validLifetime);
    doParsimUnpacking(b,this->preferredLifetime);
    doParsimUnpacking(b,this->reserved2);
    doParsimUnpacking(b,this->prefix);
}

unsigned short Ipv6NdPrefixInformation::getPrefixLength() const
{
    return this->prefixLength;
}

void Ipv6NdPrefixInformation::setPrefixLength(unsigned short prefixLength)
{
    this->prefixLength = prefixLength;
}

bool Ipv6NdPrefixInformation::getOnlinkFlag() const
{
    return this->onlinkFlag;
}

void Ipv6NdPrefixInformation::setOnlinkFlag(bool onlinkFlag)
{
    this->onlinkFlag = onlinkFlag;
}

bool Ipv6NdPrefixInformation::getAutoAddressConfFlag() const
{
    return this->autoAddressConfFlag;
}

void Ipv6NdPrefixInformation::setAutoAddressConfFlag(bool autoAddressConfFlag)
{
    this->autoAddressConfFlag = autoAddressConfFlag;
}

bool Ipv6NdPrefixInformation::getRouterAddressFlag() const
{
    return this->routerAddressFlag;
}

void Ipv6NdPrefixInformation::setRouterAddressFlag(bool routerAddressFlag)
{
    this->routerAddressFlag = routerAddressFlag;
}

unsigned int Ipv6NdPrefixInformation::getReserved1() const
{
    return this->reserved1;
}

void Ipv6NdPrefixInformation::setReserved1(unsigned int reserved1)
{
    this->reserved1 = reserved1;
}

uint32_t Ipv6NdPrefixInformation::getValidLifetime() const
{
    return this->validLifetime;
}

void Ipv6NdPrefixInformation::setValidLifetime(uint32_t validLifetime)
{
    this->validLifetime = validLifetime;
}

uint32_t Ipv6NdPrefixInformation::getPreferredLifetime() const
{
    return this->preferredLifetime;
}

void Ipv6NdPrefixInformation::setPreferredLifetime(uint32_t preferredLifetime)
{
    this->preferredLifetime = preferredLifetime;
}

uint32_t Ipv6NdPrefixInformation::getReserved2() const
{
    return this->reserved2;
}

void Ipv6NdPrefixInformation::setReserved2(uint32_t reserved2)
{
    this->reserved2 = reserved2;
}

const Ipv6Address& Ipv6NdPrefixInformation::getPrefix() const
{
    return this->prefix;
}

void Ipv6NdPrefixInformation::setPrefix(const Ipv6Address& prefix)
{
    this->prefix = prefix;
}

class Ipv6NdPrefixInformationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_prefixLength,
        FIELD_onlinkFlag,
        FIELD_autoAddressConfFlag,
        FIELD_routerAddressFlag,
        FIELD_reserved1,
        FIELD_validLifetime,
        FIELD_preferredLifetime,
        FIELD_reserved2,
        FIELD_prefix,
    };
  public:
    Ipv6NdPrefixInformationDescriptor();
    virtual ~Ipv6NdPrefixInformationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NdPrefixInformationDescriptor)

Ipv6NdPrefixInformationDescriptor::Ipv6NdPrefixInformationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NdPrefixInformation)), "inet::Ipv6NdOption")
{
    propertynames = nullptr;
}

Ipv6NdPrefixInformationDescriptor::~Ipv6NdPrefixInformationDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NdPrefixInformationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NdPrefixInformation *>(obj)!=nullptr;
}

const char **Ipv6NdPrefixInformationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NdPrefixInformationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NdPrefixInformationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ipv6NdPrefixInformationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_prefixLength
        FD_ISEDITABLE,    // FIELD_onlinkFlag
        FD_ISEDITABLE,    // FIELD_autoAddressConfFlag
        FD_ISEDITABLE,    // FIELD_routerAddressFlag
        FD_ISEDITABLE,    // FIELD_reserved1
        FD_ISEDITABLE,    // FIELD_validLifetime
        FD_ISEDITABLE,    // FIELD_preferredLifetime
        FD_ISEDITABLE,    // FIELD_reserved2
        0,    // FIELD_prefix
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6NdPrefixInformationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "prefixLength",
        "onlinkFlag",
        "autoAddressConfFlag",
        "routerAddressFlag",
        "reserved1",
        "validLifetime",
        "preferredLifetime",
        "reserved2",
        "prefix",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int Ipv6NdPrefixInformationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prefixLength") == 0) return base+0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "onlinkFlag") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "autoAddressConfFlag") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerAddressFlag") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved1") == 0) return base+4;
    if (fieldName[0] == 'v' && strcmp(fieldName, "validLifetime") == 0) return base+5;
    if (fieldName[0] == 'p' && strcmp(fieldName, "preferredLifetime") == 0) return base+6;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved2") == 0) return base+7;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prefix") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NdPrefixInformationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_prefixLength
        "bool",    // FIELD_onlinkFlag
        "bool",    // FIELD_autoAddressConfFlag
        "bool",    // FIELD_routerAddressFlag
        "unsigned int",    // FIELD_reserved1
        "uint32_t",    // FIELD_validLifetime
        "uint32_t",    // FIELD_preferredLifetime
        "uint32_t",    // FIELD_reserved2
        "inet::Ipv6Address",    // FIELD_prefix
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6NdPrefixInformationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6NdPrefixInformationDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6NdPrefixInformationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdPrefixInformation *pp = (Ipv6NdPrefixInformation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6NdPrefixInformationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdPrefixInformation *pp = (Ipv6NdPrefixInformation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6NdPrefixInformationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdPrefixInformation *pp = (Ipv6NdPrefixInformation *)object; (void)pp;
    switch (field) {
        case FIELD_prefixLength: return ulong2string(pp->getPrefixLength());
        case FIELD_onlinkFlag: return bool2string(pp->getOnlinkFlag());
        case FIELD_autoAddressConfFlag: return bool2string(pp->getAutoAddressConfFlag());
        case FIELD_routerAddressFlag: return bool2string(pp->getRouterAddressFlag());
        case FIELD_reserved1: return ulong2string(pp->getReserved1());
        case FIELD_validLifetime: return ulong2string(pp->getValidLifetime());
        case FIELD_preferredLifetime: return ulong2string(pp->getPreferredLifetime());
        case FIELD_reserved2: return ulong2string(pp->getReserved2());
        case FIELD_prefix: return pp->getPrefix().str();
        default: return "";
    }
}

bool Ipv6NdPrefixInformationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdPrefixInformation *pp = (Ipv6NdPrefixInformation *)object; (void)pp;
    switch (field) {
        case FIELD_prefixLength: pp->setPrefixLength(string2ulong(value)); return true;
        case FIELD_onlinkFlag: pp->setOnlinkFlag(string2bool(value)); return true;
        case FIELD_autoAddressConfFlag: pp->setAutoAddressConfFlag(string2bool(value)); return true;
        case FIELD_routerAddressFlag: pp->setRouterAddressFlag(string2bool(value)); return true;
        case FIELD_reserved1: pp->setReserved1(string2ulong(value)); return true;
        case FIELD_validLifetime: pp->setValidLifetime(string2ulong(value)); return true;
        case FIELD_preferredLifetime: pp->setPreferredLifetime(string2ulong(value)); return true;
        case FIELD_reserved2: pp->setReserved2(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ipv6NdPrefixInformationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ipv6NdPrefixInformationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdPrefixInformation *pp = (Ipv6NdPrefixInformation *)object; (void)pp;
    switch (field) {
        case FIELD_prefix: return toVoidPtr(&pp->getPrefix()); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6NdMtu)

Ipv6NdMtu::Ipv6NdMtu() : ::inet::Ipv6NdOption()
{
    this->setType(IPv6ND_MTU);
    this->setOptionLength(1);

}

Ipv6NdMtu::Ipv6NdMtu(const Ipv6NdMtu& other) : ::inet::Ipv6NdOption(other)
{
    copy(other);
}

Ipv6NdMtu::~Ipv6NdMtu()
{
}

Ipv6NdMtu& Ipv6NdMtu::operator=(const Ipv6NdMtu& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdOption::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NdMtu::copy(const Ipv6NdMtu& other)
{
    this->reserved = other.reserved;
    this->mtu = other.mtu;
}

void Ipv6NdMtu::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdOption::parsimPack(b);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->mtu);
}

void Ipv6NdMtu::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdOption::parsimUnpack(b);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->mtu);
}

uint16_t Ipv6NdMtu::getReserved() const
{
    return this->reserved;
}

void Ipv6NdMtu::setReserved(uint16_t reserved)
{
    this->reserved = reserved;
}

uint32_t Ipv6NdMtu::getMtu() const
{
    return this->mtu;
}

void Ipv6NdMtu::setMtu(uint32_t mtu)
{
    this->mtu = mtu;
}

class Ipv6NdMtuDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reserved,
        FIELD_mtu,
    };
  public:
    Ipv6NdMtuDescriptor();
    virtual ~Ipv6NdMtuDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NdMtuDescriptor)

Ipv6NdMtuDescriptor::Ipv6NdMtuDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NdMtu)), "inet::Ipv6NdOption")
{
    propertynames = nullptr;
}

Ipv6NdMtuDescriptor::~Ipv6NdMtuDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NdMtuDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NdMtu *>(obj)!=nullptr;
}

const char **Ipv6NdMtuDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NdMtuDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NdMtuDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ipv6NdMtuDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_mtu
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6NdMtuDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reserved",
        "mtu",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ipv6NdMtuDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mtu") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NdMtuDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_reserved
        "uint32_t",    // FIELD_mtu
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6NdMtuDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6NdMtuDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6NdMtuDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdMtu *pp = (Ipv6NdMtu *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6NdMtuDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdMtu *pp = (Ipv6NdMtu *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6NdMtuDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdMtu *pp = (Ipv6NdMtu *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_mtu: return ulong2string(pp->getMtu());
        default: return "";
    }
}

bool Ipv6NdMtuDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdMtu *pp = (Ipv6NdMtu *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: pp->setReserved(string2ulong(value)); return true;
        case FIELD_mtu: pp->setMtu(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ipv6NdMtuDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ipv6NdMtuDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdMtu *pp = (Ipv6NdMtu *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Mipv6NdAdvertisementInterval)

Mipv6NdAdvertisementInterval::Mipv6NdAdvertisementInterval() : ::inet::Ipv6NdOption()
{
    this->setType(IPv6ND_ADVERTISEMENT_INTERVAL);
    this->setOptionLength(1);

}

Mipv6NdAdvertisementInterval::Mipv6NdAdvertisementInterval(const Mipv6NdAdvertisementInterval& other) : ::inet::Ipv6NdOption(other)
{
    copy(other);
}

Mipv6NdAdvertisementInterval::~Mipv6NdAdvertisementInterval()
{
}

Mipv6NdAdvertisementInterval& Mipv6NdAdvertisementInterval::operator=(const Mipv6NdAdvertisementInterval& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdOption::operator=(other);
    copy(other);
    return *this;
}

void Mipv6NdAdvertisementInterval::copy(const Mipv6NdAdvertisementInterval& other)
{
    this->reserved = other.reserved;
    this->advertisementInterval = other.advertisementInterval;
}

void Mipv6NdAdvertisementInterval::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdOption::parsimPack(b);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->advertisementInterval);
}

void Mipv6NdAdvertisementInterval::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdOption::parsimUnpack(b);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->advertisementInterval);
}

uint16_t Mipv6NdAdvertisementInterval::getReserved() const
{
    return this->reserved;
}

void Mipv6NdAdvertisementInterval::setReserved(uint16_t reserved)
{
    this->reserved = reserved;
}

uint32_t Mipv6NdAdvertisementInterval::getAdvertisementInterval() const
{
    return this->advertisementInterval;
}

void Mipv6NdAdvertisementInterval::setAdvertisementInterval(uint32_t advertisementInterval)
{
    this->advertisementInterval = advertisementInterval;
}

class Mipv6NdAdvertisementIntervalDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reserved,
        FIELD_advertisementInterval,
    };
  public:
    Mipv6NdAdvertisementIntervalDescriptor();
    virtual ~Mipv6NdAdvertisementIntervalDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Mipv6NdAdvertisementIntervalDescriptor)

Mipv6NdAdvertisementIntervalDescriptor::Mipv6NdAdvertisementIntervalDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Mipv6NdAdvertisementInterval)), "inet::Ipv6NdOption")
{
    propertynames = nullptr;
}

Mipv6NdAdvertisementIntervalDescriptor::~Mipv6NdAdvertisementIntervalDescriptor()
{
    delete[] propertynames;
}

bool Mipv6NdAdvertisementIntervalDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Mipv6NdAdvertisementInterval *>(obj)!=nullptr;
}

const char **Mipv6NdAdvertisementIntervalDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Mipv6NdAdvertisementIntervalDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Mipv6NdAdvertisementIntervalDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Mipv6NdAdvertisementIntervalDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_advertisementInterval
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Mipv6NdAdvertisementIntervalDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reserved",
        "advertisementInterval",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Mipv6NdAdvertisementIntervalDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "advertisementInterval") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Mipv6NdAdvertisementIntervalDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_reserved
        "uint32_t",    // FIELD_advertisementInterval
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Mipv6NdAdvertisementIntervalDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Mipv6NdAdvertisementIntervalDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Mipv6NdAdvertisementIntervalDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Mipv6NdAdvertisementInterval *pp = (Mipv6NdAdvertisementInterval *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Mipv6NdAdvertisementIntervalDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Mipv6NdAdvertisementInterval *pp = (Mipv6NdAdvertisementInterval *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Mipv6NdAdvertisementIntervalDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Mipv6NdAdvertisementInterval *pp = (Mipv6NdAdvertisementInterval *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_advertisementInterval: return ulong2string(pp->getAdvertisementInterval());
        default: return "";
    }
}

bool Mipv6NdAdvertisementIntervalDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Mipv6NdAdvertisementInterval *pp = (Mipv6NdAdvertisementInterval *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: pp->setReserved(string2ulong(value)); return true;
        case FIELD_advertisementInterval: pp->setAdvertisementInterval(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Mipv6NdAdvertisementIntervalDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Mipv6NdAdvertisementIntervalDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Mipv6NdAdvertisementInterval *pp = (Mipv6NdAdvertisementInterval *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Mipv6HaInformation)

Mipv6HaInformation::Mipv6HaInformation() : ::inet::Ipv6NdOption()
{
    this->setType(IPv6ND_HOME_AGENT_INFORMATION_OPTION);
    this->setOptionLength(1);

}

Mipv6HaInformation::Mipv6HaInformation(const Mipv6HaInformation& other) : ::inet::Ipv6NdOption(other)
{
    copy(other);
}

Mipv6HaInformation::~Mipv6HaInformation()
{
}

Mipv6HaInformation& Mipv6HaInformation::operator=(const Mipv6HaInformation& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdOption::operator=(other);
    copy(other);
    return *this;
}

void Mipv6HaInformation::copy(const Mipv6HaInformation& other)
{
    this->reserved = other.reserved;
    this->homeAgentPreference = other.homeAgentPreference;
    this->homeAgentLifetime = other.homeAgentLifetime;
}

void Mipv6HaInformation::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdOption::parsimPack(b);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->homeAgentPreference);
    doParsimPacking(b,this->homeAgentLifetime);
}

void Mipv6HaInformation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdOption::parsimUnpack(b);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->homeAgentPreference);
    doParsimUnpacking(b,this->homeAgentLifetime);
}

uint16_t Mipv6HaInformation::getReserved() const
{
    return this->reserved;
}

void Mipv6HaInformation::setReserved(uint16_t reserved)
{
    this->reserved = reserved;
}

uint16_t Mipv6HaInformation::getHomeAgentPreference() const
{
    return this->homeAgentPreference;
}

void Mipv6HaInformation::setHomeAgentPreference(uint16_t homeAgentPreference)
{
    this->homeAgentPreference = homeAgentPreference;
}

uint16_t Mipv6HaInformation::getHomeAgentLifetime() const
{
    return this->homeAgentLifetime;
}

void Mipv6HaInformation::setHomeAgentLifetime(uint16_t homeAgentLifetime)
{
    this->homeAgentLifetime = homeAgentLifetime;
}

class Mipv6HaInformationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reserved,
        FIELD_homeAgentPreference,
        FIELD_homeAgentLifetime,
    };
  public:
    Mipv6HaInformationDescriptor();
    virtual ~Mipv6HaInformationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Mipv6HaInformationDescriptor)

Mipv6HaInformationDescriptor::Mipv6HaInformationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Mipv6HaInformation)), "inet::Ipv6NdOption")
{
    propertynames = nullptr;
}

Mipv6HaInformationDescriptor::~Mipv6HaInformationDescriptor()
{
    delete[] propertynames;
}

bool Mipv6HaInformationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Mipv6HaInformation *>(obj)!=nullptr;
}

const char **Mipv6HaInformationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Mipv6HaInformationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Mipv6HaInformationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Mipv6HaInformationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_homeAgentPreference
        FD_ISEDITABLE,    // FIELD_homeAgentLifetime
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Mipv6HaInformationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reserved",
        "homeAgentPreference",
        "homeAgentLifetime",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Mipv6HaInformationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "homeAgentPreference") == 0) return base+1;
    if (fieldName[0] == 'h' && strcmp(fieldName, "homeAgentLifetime") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Mipv6HaInformationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_reserved
        "uint16_t",    // FIELD_homeAgentPreference
        "uint16_t",    // FIELD_homeAgentLifetime
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Mipv6HaInformationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Mipv6HaInformationDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Mipv6HaInformationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Mipv6HaInformation *pp = (Mipv6HaInformation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Mipv6HaInformationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Mipv6HaInformation *pp = (Mipv6HaInformation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Mipv6HaInformationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Mipv6HaInformation *pp = (Mipv6HaInformation *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_homeAgentPreference: return ulong2string(pp->getHomeAgentPreference());
        case FIELD_homeAgentLifetime: return ulong2string(pp->getHomeAgentLifetime());
        default: return "";
    }
}

bool Mipv6HaInformationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Mipv6HaInformation *pp = (Mipv6HaInformation *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: pp->setReserved(string2ulong(value)); return true;
        case FIELD_homeAgentPreference: pp->setHomeAgentPreference(string2ulong(value)); return true;
        case FIELD_homeAgentLifetime: pp->setHomeAgentLifetime(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Mipv6HaInformationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Mipv6HaInformationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Mipv6HaInformation *pp = (Mipv6HaInformation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv6NdOptions)

Ipv6NdOptions::Ipv6NdOptions() : ::omnetpp::cObject()
{
}

Ipv6NdOptions::Ipv6NdOptions(const Ipv6NdOptions& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ipv6NdOptions::~Ipv6NdOptions()
{
    for (size_t i = 0; i < option_arraysize; i++)
        delete this->option[i];
    delete [] this->option;
}

Ipv6NdOptions& Ipv6NdOptions::operator=(const Ipv6NdOptions& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NdOptions::copy(const Ipv6NdOptions& other)
{
    for (size_t i = 0; i < option_arraysize; i++)
        delete this->option[i];
    delete [] this->option;
    this->option = (other.option_arraysize==0) ? nullptr : new Ipv6NdOption *[other.option_arraysize];
    option_arraysize = other.option_arraysize;
    for (size_t i = 0; i < option_arraysize; i++) {
        this->option[i] = other.option[i];
        if (this->option[i] != nullptr) {
            this->option[i] = this->option[i]->dup();
        }
    }
}

void Ipv6NdOptions::parsimPack(omnetpp::cCommBuffer *b) const
{
    b->pack(option_arraysize);
    doParsimArrayPacking(b,this->option,option_arraysize);
}

void Ipv6NdOptions::parsimUnpack(omnetpp::cCommBuffer *b)
{
    delete [] this->option;
    b->unpack(option_arraysize);
    if (option_arraysize == 0) {
        this->option = nullptr;
    } else {
        this->option = new Ipv6NdOption *[option_arraysize];
        doParsimArrayUnpacking(b,this->option,option_arraysize);
    }
}

size_t Ipv6NdOptions::getOptionArraySize() const
{
    return option_arraysize;
}

const Ipv6NdOption * Ipv6NdOptions::getOption(size_t k) const
{
    if (k >= option_arraysize) throw omnetpp::cRuntimeError("Array of size option_arraysize indexed by %lu", (unsigned long)k);
    return this->option[k];
}

void Ipv6NdOptions::setOptionArraySize(size_t newSize)
{
    Ipv6NdOption * *option2 = (newSize==0) ? nullptr : new Ipv6NdOption *[newSize];
    size_t minSize = option_arraysize < newSize ? option_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        option2[i] = this->option[i];
    for (size_t i = minSize; i < newSize; i++)
        option2[i] = nullptr;
    for (size_t i = newSize; i < option_arraysize; i++)
        delete option[i];
    delete [] this->option;
    this->option = option2;
    option_arraysize = newSize;
}

void Ipv6NdOptions::setOption(size_t k, Ipv6NdOption * option)
{
    if (k >= option_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    if (this->option[k] != nullptr) throw omnetpp::cRuntimeError("setOption(): a value is already set, remove it first with dropOption()");
    this->option[k] = option;
}

Ipv6NdOption * Ipv6NdOptions::dropOption(size_t k)
{
    if (k >= option_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    Ipv6NdOption * retval = this->option[k];
    this->option[k] = nullptr;
    return retval;
}

void Ipv6NdOptions::insertOption(size_t k, Ipv6NdOption * option)
{
    if (k > option_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = option_arraysize + 1;
    Ipv6NdOption * *option2 = new Ipv6NdOption *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        option2[i] = this->option[i];
    option2[k] = option;
    for (i = k + 1; i < newSize; i++)
        option2[i] = this->option[i-1];
    delete [] this->option;
    this->option = option2;
    option_arraysize = newSize;
}

void Ipv6NdOptions::insertOption(Ipv6NdOption * option)
{
    insertOption(option_arraysize, option);
}

void Ipv6NdOptions::eraseOption(size_t k)
{
    if (k >= option_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = option_arraysize - 1;
    Ipv6NdOption * *option2 = (newSize == 0) ? nullptr : new Ipv6NdOption *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        option2[i] = this->option[i];
    for (i = k; i < newSize; i++)
        option2[i] = this->option[i+1];
    delete this->option[k];
    delete [] this->option;
    this->option = option2;
    option_arraysize = newSize;
}

class Ipv6NdOptionsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_option,
    };
  public:
    Ipv6NdOptionsDescriptor();
    virtual ~Ipv6NdOptionsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NdOptionsDescriptor)

Ipv6NdOptionsDescriptor::Ipv6NdOptionsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NdOptions)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ipv6NdOptionsDescriptor::~Ipv6NdOptionsDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NdOptionsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NdOptions *>(obj)!=nullptr;
}

const char **Ipv6NdOptionsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NdOptionsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NdOptionsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ipv6NdOptionsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_option
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6NdOptionsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "option",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ipv6NdOptionsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "option") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NdOptionsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv6NdOption",    // FIELD_option
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6NdOptionsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_option: {
            static const char *names[] = { "owned",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ipv6NdOptionsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_option:
            if (!strcmp(propertyname, "owned")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int Ipv6NdOptionsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdOptions *pp = (Ipv6NdOptions *)object; (void)pp;
    switch (field) {
        case FIELD_option: return pp->getOptionArraySize();
        default: return 0;
    }
}

const char *Ipv6NdOptionsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdOptions *pp = (Ipv6NdOptions *)object; (void)pp;
    switch (field) {
        case FIELD_option: { const Ipv6NdOption * value = pp->getOption(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string Ipv6NdOptionsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdOptions *pp = (Ipv6NdOptions *)object; (void)pp;
    switch (field) {
        case FIELD_option: {std::stringstream out; out << pp->getOption(i); return out.str();}
        default: return "";
    }
}

bool Ipv6NdOptionsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdOptions *pp = (Ipv6NdOptions *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6NdOptionsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_option: return omnetpp::opp_typename(typeid(Ipv6NdOption));
        default: return nullptr;
    };
}

void *Ipv6NdOptionsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdOptions *pp = (Ipv6NdOptions *)object; (void)pp;
    switch (field) {
        case FIELD_option: return toVoidPtr(pp->getOption(i)); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6NdMessage)

Ipv6NdMessage::Ipv6NdMessage() : ::inet::Icmpv6Header()
{
}

Ipv6NdMessage::Ipv6NdMessage(const Ipv6NdMessage& other) : ::inet::Icmpv6Header(other)
{
    copy(other);
}

Ipv6NdMessage::~Ipv6NdMessage()
{
}

Ipv6NdMessage& Ipv6NdMessage::operator=(const Ipv6NdMessage& other)
{
    if (this == &other) return *this;
    ::inet::Icmpv6Header::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NdMessage::copy(const Ipv6NdMessage& other)
{
    this->code = other.code;
}

void Ipv6NdMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Icmpv6Header::parsimPack(b);
    doParsimPacking(b,this->code);
}

void Ipv6NdMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Icmpv6Header::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
}

int Ipv6NdMessage::getCode() const
{
    return this->code;
}

void Ipv6NdMessage::setCode(int code)
{
    handleChange();
    this->code = code;
}

class Ipv6NdMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_code,
    };
  public:
    Ipv6NdMessageDescriptor();
    virtual ~Ipv6NdMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NdMessageDescriptor)

Ipv6NdMessageDescriptor::Ipv6NdMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NdMessage)), "inet::Icmpv6Header")
{
    propertynames = nullptr;
}

Ipv6NdMessageDescriptor::~Ipv6NdMessageDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NdMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NdMessage *>(obj)!=nullptr;
}

const char **Ipv6NdMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NdMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NdMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ipv6NdMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_code
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6NdMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ipv6NdMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "code") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NdMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_code
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6NdMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6NdMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6NdMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdMessage *pp = (Ipv6NdMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6NdMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdMessage *pp = (Ipv6NdMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6NdMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdMessage *pp = (Ipv6NdMessage *)object; (void)pp;
    switch (field) {
        case FIELD_code: return long2string(pp->getCode());
        default: return "";
    }
}

bool Ipv6NdMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdMessage *pp = (Ipv6NdMessage *)object; (void)pp;
    switch (field) {
        case FIELD_code: pp->setCode(string2long(value)); return true;
        default: return false;
    }
}

const char *Ipv6NdMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ipv6NdMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdMessage *pp = (Ipv6NdMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv6RouterSolicitation)

Ipv6RouterSolicitation::Ipv6RouterSolicitation() : ::inet::Ipv6NdMessage()
{
    this->setChunkLength(B(8));
    this->setType(ICMPv6_ROUTER_SOL);

}

Ipv6RouterSolicitation::Ipv6RouterSolicitation(const Ipv6RouterSolicitation& other) : ::inet::Ipv6NdMessage(other)
{
    copy(other);
}

Ipv6RouterSolicitation::~Ipv6RouterSolicitation()
{
}

Ipv6RouterSolicitation& Ipv6RouterSolicitation::operator=(const Ipv6RouterSolicitation& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdMessage::operator=(other);
    copy(other);
    return *this;
}

void Ipv6RouterSolicitation::copy(const Ipv6RouterSolicitation& other)
{
    this->reserved = other.reserved;
    this->options = other.options;
}

void Ipv6RouterSolicitation::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdMessage::parsimPack(b);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->options);
}

void Ipv6RouterSolicitation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->options);
}

uint32_t Ipv6RouterSolicitation::getReserved() const
{
    return this->reserved;
}

void Ipv6RouterSolicitation::setReserved(uint32_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

const Ipv6NdOptions& Ipv6RouterSolicitation::getOptions() const
{
    return this->options;
}

void Ipv6RouterSolicitation::setOptions(const Ipv6NdOptions& options)
{
    handleChange();
    this->options = options;
}

class Ipv6RouterSolicitationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reserved,
        FIELD_options,
    };
  public:
    Ipv6RouterSolicitationDescriptor();
    virtual ~Ipv6RouterSolicitationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6RouterSolicitationDescriptor)

Ipv6RouterSolicitationDescriptor::Ipv6RouterSolicitationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6RouterSolicitation)), "inet::Ipv6NdMessage")
{
    propertynames = nullptr;
}

Ipv6RouterSolicitationDescriptor::~Ipv6RouterSolicitationDescriptor()
{
    delete[] propertynames;
}

bool Ipv6RouterSolicitationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6RouterSolicitation *>(obj)!=nullptr;
}

const char **Ipv6RouterSolicitationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6RouterSolicitationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6RouterSolicitationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ipv6RouterSolicitationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_options
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6RouterSolicitationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reserved",
        "options",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ipv6RouterSolicitationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6RouterSolicitationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_reserved
        "inet::Ipv6NdOptions",    // FIELD_options
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6RouterSolicitationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6RouterSolicitationDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6RouterSolicitationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6RouterSolicitation *pp = (Ipv6RouterSolicitation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6RouterSolicitationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6RouterSolicitation *pp = (Ipv6RouterSolicitation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6RouterSolicitationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6RouterSolicitation *pp = (Ipv6RouterSolicitation *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_options: {std::stringstream out; out << pp->getOptions(); return out.str();}
        default: return "";
    }
}

bool Ipv6RouterSolicitationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6RouterSolicitation *pp = (Ipv6RouterSolicitation *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: pp->setReserved(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ipv6RouterSolicitationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(Ipv6NdOptions));
        default: return nullptr;
    };
}

void *Ipv6RouterSolicitationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6RouterSolicitation *pp = (Ipv6RouterSolicitation *)object; (void)pp;
    switch (field) {
        case FIELD_options: return toVoidPtr(&pp->getOptions()); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6RouterAdvertisement)

Ipv6RouterAdvertisement::Ipv6RouterAdvertisement() : ::inet::Ipv6NdMessage()
{
    this->setChunkLength(B(16));
    this->setType(ICMPv6_ROUTER_AD);

}

Ipv6RouterAdvertisement::Ipv6RouterAdvertisement(const Ipv6RouterAdvertisement& other) : ::inet::Ipv6NdMessage(other)
{
    copy(other);
}

Ipv6RouterAdvertisement::~Ipv6RouterAdvertisement()
{
}

Ipv6RouterAdvertisement& Ipv6RouterAdvertisement::operator=(const Ipv6RouterAdvertisement& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdMessage::operator=(other);
    copy(other);
    return *this;
}

void Ipv6RouterAdvertisement::copy(const Ipv6RouterAdvertisement& other)
{
    this->curHopLimit = other.curHopLimit;
    this->managedAddrConfFlag = other.managedAddrConfFlag;
    this->otherStatefulConfFlag = other.otherStatefulConfFlag;
    this->homeAgentFlag = other.homeAgentFlag;
    this->reserved = other.reserved;
    this->routerLifetime = other.routerLifetime;
    this->reachableTime = other.reachableTime;
    this->retransTimer = other.retransTimer;
    this->options = other.options;
}

void Ipv6RouterAdvertisement::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdMessage::parsimPack(b);
    doParsimPacking(b,this->curHopLimit);
    doParsimPacking(b,this->managedAddrConfFlag);
    doParsimPacking(b,this->otherStatefulConfFlag);
    doParsimPacking(b,this->homeAgentFlag);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->routerLifetime);
    doParsimPacking(b,this->reachableTime);
    doParsimPacking(b,this->retransTimer);
    doParsimPacking(b,this->options);
}

void Ipv6RouterAdvertisement::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->curHopLimit);
    doParsimUnpacking(b,this->managedAddrConfFlag);
    doParsimUnpacking(b,this->otherStatefulConfFlag);
    doParsimUnpacking(b,this->homeAgentFlag);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->routerLifetime);
    doParsimUnpacking(b,this->reachableTime);
    doParsimUnpacking(b,this->retransTimer);
    doParsimUnpacking(b,this->options);
}

unsigned short Ipv6RouterAdvertisement::getCurHopLimit() const
{
    return this->curHopLimit;
}

void Ipv6RouterAdvertisement::setCurHopLimit(unsigned short curHopLimit)
{
    handleChange();
    this->curHopLimit = curHopLimit;
}

bool Ipv6RouterAdvertisement::getManagedAddrConfFlag() const
{
    return this->managedAddrConfFlag;
}

void Ipv6RouterAdvertisement::setManagedAddrConfFlag(bool managedAddrConfFlag)
{
    handleChange();
    this->managedAddrConfFlag = managedAddrConfFlag;
}

bool Ipv6RouterAdvertisement::getOtherStatefulConfFlag() const
{
    return this->otherStatefulConfFlag;
}

void Ipv6RouterAdvertisement::setOtherStatefulConfFlag(bool otherStatefulConfFlag)
{
    handleChange();
    this->otherStatefulConfFlag = otherStatefulConfFlag;
}

bool Ipv6RouterAdvertisement::getHomeAgentFlag() const
{
    return this->homeAgentFlag;
}

void Ipv6RouterAdvertisement::setHomeAgentFlag(bool homeAgentFlag)
{
    handleChange();
    this->homeAgentFlag = homeAgentFlag;
}

uint8_t Ipv6RouterAdvertisement::getReserved() const
{
    return this->reserved;
}

void Ipv6RouterAdvertisement::setReserved(uint8_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

unsigned short Ipv6RouterAdvertisement::getRouterLifetime() const
{
    return this->routerLifetime;
}

void Ipv6RouterAdvertisement::setRouterLifetime(unsigned short routerLifetime)
{
    handleChange();
    this->routerLifetime = routerLifetime;
}

unsigned int Ipv6RouterAdvertisement::getReachableTime() const
{
    return this->reachableTime;
}

void Ipv6RouterAdvertisement::setReachableTime(unsigned int reachableTime)
{
    handleChange();
    this->reachableTime = reachableTime;
}

unsigned int Ipv6RouterAdvertisement::getRetransTimer() const
{
    return this->retransTimer;
}

void Ipv6RouterAdvertisement::setRetransTimer(unsigned int retransTimer)
{
    handleChange();
    this->retransTimer = retransTimer;
}

const Ipv6NdOptions& Ipv6RouterAdvertisement::getOptions() const
{
    return this->options;
}

void Ipv6RouterAdvertisement::setOptions(const Ipv6NdOptions& options)
{
    handleChange();
    this->options = options;
}

class Ipv6RouterAdvertisementDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_curHopLimit,
        FIELD_managedAddrConfFlag,
        FIELD_otherStatefulConfFlag,
        FIELD_homeAgentFlag,
        FIELD_reserved,
        FIELD_routerLifetime,
        FIELD_reachableTime,
        FIELD_retransTimer,
        FIELD_options,
    };
  public:
    Ipv6RouterAdvertisementDescriptor();
    virtual ~Ipv6RouterAdvertisementDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6RouterAdvertisementDescriptor)

Ipv6RouterAdvertisementDescriptor::Ipv6RouterAdvertisementDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6RouterAdvertisement)), "inet::Ipv6NdMessage")
{
    propertynames = nullptr;
}

Ipv6RouterAdvertisementDescriptor::~Ipv6RouterAdvertisementDescriptor()
{
    delete[] propertynames;
}

bool Ipv6RouterAdvertisementDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6RouterAdvertisement *>(obj)!=nullptr;
}

const char **Ipv6RouterAdvertisementDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6RouterAdvertisementDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6RouterAdvertisementDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ipv6RouterAdvertisementDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_curHopLimit
        FD_ISEDITABLE,    // FIELD_managedAddrConfFlag
        FD_ISEDITABLE,    // FIELD_otherStatefulConfFlag
        FD_ISEDITABLE,    // FIELD_homeAgentFlag
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_routerLifetime
        FD_ISEDITABLE,    // FIELD_reachableTime
        FD_ISEDITABLE,    // FIELD_retransTimer
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_options
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6RouterAdvertisementDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "curHopLimit",
        "managedAddrConfFlag",
        "otherStatefulConfFlag",
        "homeAgentFlag",
        "reserved",
        "routerLifetime",
        "reachableTime",
        "retransTimer",
        "options",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int Ipv6RouterAdvertisementDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "curHopLimit") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "managedAddrConfFlag") == 0) return base+1;
    if (fieldName[0] == 'o' && strcmp(fieldName, "otherStatefulConfFlag") == 0) return base+2;
    if (fieldName[0] == 'h' && strcmp(fieldName, "homeAgentFlag") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+4;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerLifetime") == 0) return base+5;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reachableTime") == 0) return base+6;
    if (fieldName[0] == 'r' && strcmp(fieldName, "retransTimer") == 0) return base+7;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6RouterAdvertisementDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_curHopLimit
        "bool",    // FIELD_managedAddrConfFlag
        "bool",    // FIELD_otherStatefulConfFlag
        "bool",    // FIELD_homeAgentFlag
        "uint8_t",    // FIELD_reserved
        "unsigned short",    // FIELD_routerLifetime
        "unsigned int",    // FIELD_reachableTime
        "unsigned int",    // FIELD_retransTimer
        "inet::Ipv6NdOptions",    // FIELD_options
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6RouterAdvertisementDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6RouterAdvertisementDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6RouterAdvertisementDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6RouterAdvertisement *pp = (Ipv6RouterAdvertisement *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6RouterAdvertisementDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6RouterAdvertisement *pp = (Ipv6RouterAdvertisement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6RouterAdvertisementDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6RouterAdvertisement *pp = (Ipv6RouterAdvertisement *)object; (void)pp;
    switch (field) {
        case FIELD_curHopLimit: return ulong2string(pp->getCurHopLimit());
        case FIELD_managedAddrConfFlag: return bool2string(pp->getManagedAddrConfFlag());
        case FIELD_otherStatefulConfFlag: return bool2string(pp->getOtherStatefulConfFlag());
        case FIELD_homeAgentFlag: return bool2string(pp->getHomeAgentFlag());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_routerLifetime: return ulong2string(pp->getRouterLifetime());
        case FIELD_reachableTime: return ulong2string(pp->getReachableTime());
        case FIELD_retransTimer: return ulong2string(pp->getRetransTimer());
        case FIELD_options: {std::stringstream out; out << pp->getOptions(); return out.str();}
        default: return "";
    }
}

bool Ipv6RouterAdvertisementDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6RouterAdvertisement *pp = (Ipv6RouterAdvertisement *)object; (void)pp;
    switch (field) {
        case FIELD_curHopLimit: pp->setCurHopLimit(string2ulong(value)); return true;
        case FIELD_managedAddrConfFlag: pp->setManagedAddrConfFlag(string2bool(value)); return true;
        case FIELD_otherStatefulConfFlag: pp->setOtherStatefulConfFlag(string2bool(value)); return true;
        case FIELD_homeAgentFlag: pp->setHomeAgentFlag(string2bool(value)); return true;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); return true;
        case FIELD_routerLifetime: pp->setRouterLifetime(string2ulong(value)); return true;
        case FIELD_reachableTime: pp->setReachableTime(string2ulong(value)); return true;
        case FIELD_retransTimer: pp->setRetransTimer(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ipv6RouterAdvertisementDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(Ipv6NdOptions));
        default: return nullptr;
    };
}

void *Ipv6RouterAdvertisementDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6RouterAdvertisement *pp = (Ipv6RouterAdvertisement *)object; (void)pp;
    switch (field) {
        case FIELD_options: return toVoidPtr(&pp->getOptions()); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6NeighbourSolicitation)

Ipv6NeighbourSolicitation::Ipv6NeighbourSolicitation() : ::inet::Ipv6NdMessage()
{
    this->setChunkLength(B(24));
    this->setType(ICMPv6_NEIGHBOUR_SOL);

}

Ipv6NeighbourSolicitation::Ipv6NeighbourSolicitation(const Ipv6NeighbourSolicitation& other) : ::inet::Ipv6NdMessage(other)
{
    copy(other);
}

Ipv6NeighbourSolicitation::~Ipv6NeighbourSolicitation()
{
}

Ipv6NeighbourSolicitation& Ipv6NeighbourSolicitation::operator=(const Ipv6NeighbourSolicitation& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdMessage::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NeighbourSolicitation::copy(const Ipv6NeighbourSolicitation& other)
{
    this->reserved = other.reserved;
    this->targetAddress = other.targetAddress;
    this->options = other.options;
}

void Ipv6NeighbourSolicitation::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdMessage::parsimPack(b);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->targetAddress);
    doParsimPacking(b,this->options);
}

void Ipv6NeighbourSolicitation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->targetAddress);
    doParsimUnpacking(b,this->options);
}

uint32_t Ipv6NeighbourSolicitation::getReserved() const
{
    return this->reserved;
}

void Ipv6NeighbourSolicitation::setReserved(uint32_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

const Ipv6Address& Ipv6NeighbourSolicitation::getTargetAddress() const
{
    return this->targetAddress;
}

void Ipv6NeighbourSolicitation::setTargetAddress(const Ipv6Address& targetAddress)
{
    handleChange();
    this->targetAddress = targetAddress;
}

const Ipv6NdOptions& Ipv6NeighbourSolicitation::getOptions() const
{
    return this->options;
}

void Ipv6NeighbourSolicitation::setOptions(const Ipv6NdOptions& options)
{
    handleChange();
    this->options = options;
}

class Ipv6NeighbourSolicitationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reserved,
        FIELD_targetAddress,
        FIELD_options,
    };
  public:
    Ipv6NeighbourSolicitationDescriptor();
    virtual ~Ipv6NeighbourSolicitationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NeighbourSolicitationDescriptor)

Ipv6NeighbourSolicitationDescriptor::Ipv6NeighbourSolicitationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NeighbourSolicitation)), "inet::Ipv6NdMessage")
{
    propertynames = nullptr;
}

Ipv6NeighbourSolicitationDescriptor::~Ipv6NeighbourSolicitationDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NeighbourSolicitationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NeighbourSolicitation *>(obj)!=nullptr;
}

const char **Ipv6NeighbourSolicitationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NeighbourSolicitationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NeighbourSolicitationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ipv6NeighbourSolicitationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_reserved
        0,    // FIELD_targetAddress
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_options
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6NeighbourSolicitationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reserved",
        "targetAddress",
        "options",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ipv6NeighbourSolicitationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "targetAddress") == 0) return base+1;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NeighbourSolicitationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_reserved
        "inet::Ipv6Address",    // FIELD_targetAddress
        "inet::Ipv6NdOptions",    // FIELD_options
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6NeighbourSolicitationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6NeighbourSolicitationDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6NeighbourSolicitationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NeighbourSolicitation *pp = (Ipv6NeighbourSolicitation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6NeighbourSolicitationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NeighbourSolicitation *pp = (Ipv6NeighbourSolicitation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6NeighbourSolicitationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NeighbourSolicitation *pp = (Ipv6NeighbourSolicitation *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_targetAddress: return pp->getTargetAddress().str();
        case FIELD_options: {std::stringstream out; out << pp->getOptions(); return out.str();}
        default: return "";
    }
}

bool Ipv6NeighbourSolicitationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NeighbourSolicitation *pp = (Ipv6NeighbourSolicitation *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: pp->setReserved(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ipv6NeighbourSolicitationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(Ipv6NdOptions));
        default: return nullptr;
    };
}

void *Ipv6NeighbourSolicitationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NeighbourSolicitation *pp = (Ipv6NeighbourSolicitation *)object; (void)pp;
    switch (field) {
        case FIELD_targetAddress: return toVoidPtr(&pp->getTargetAddress()); break;
        case FIELD_options: return toVoidPtr(&pp->getOptions()); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6NeighbourAdvertisement)

Ipv6NeighbourAdvertisement::Ipv6NeighbourAdvertisement() : ::inet::Ipv6NdMessage()
{
    this->setChunkLength(B(24));
    this->setType(ICMPv6_NEIGHBOUR_AD);

}

Ipv6NeighbourAdvertisement::Ipv6NeighbourAdvertisement(const Ipv6NeighbourAdvertisement& other) : ::inet::Ipv6NdMessage(other)
{
    copy(other);
}

Ipv6NeighbourAdvertisement::~Ipv6NeighbourAdvertisement()
{
}

Ipv6NeighbourAdvertisement& Ipv6NeighbourAdvertisement::operator=(const Ipv6NeighbourAdvertisement& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdMessage::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NeighbourAdvertisement::copy(const Ipv6NeighbourAdvertisement& other)
{
    this->routerFlag = other.routerFlag;
    this->solicitedFlag = other.solicitedFlag;
    this->overrideFlag = other.overrideFlag;
    this->reserved = other.reserved;
    this->targetAddress = other.targetAddress;
    this->options = other.options;
}

void Ipv6NeighbourAdvertisement::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdMessage::parsimPack(b);
    doParsimPacking(b,this->routerFlag);
    doParsimPacking(b,this->solicitedFlag);
    doParsimPacking(b,this->overrideFlag);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->targetAddress);
    doParsimPacking(b,this->options);
}

void Ipv6NeighbourAdvertisement::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->routerFlag);
    doParsimUnpacking(b,this->solicitedFlag);
    doParsimUnpacking(b,this->overrideFlag);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->targetAddress);
    doParsimUnpacking(b,this->options);
}

bool Ipv6NeighbourAdvertisement::getRouterFlag() const
{
    return this->routerFlag;
}

void Ipv6NeighbourAdvertisement::setRouterFlag(bool routerFlag)
{
    handleChange();
    this->routerFlag = routerFlag;
}

bool Ipv6NeighbourAdvertisement::getSolicitedFlag() const
{
    return this->solicitedFlag;
}

void Ipv6NeighbourAdvertisement::setSolicitedFlag(bool solicitedFlag)
{
    handleChange();
    this->solicitedFlag = solicitedFlag;
}

bool Ipv6NeighbourAdvertisement::getOverrideFlag() const
{
    return this->overrideFlag;
}

void Ipv6NeighbourAdvertisement::setOverrideFlag(bool overrideFlag)
{
    handleChange();
    this->overrideFlag = overrideFlag;
}

uint32_t Ipv6NeighbourAdvertisement::getReserved() const
{
    return this->reserved;
}

void Ipv6NeighbourAdvertisement::setReserved(uint32_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

const Ipv6Address& Ipv6NeighbourAdvertisement::getTargetAddress() const
{
    return this->targetAddress;
}

void Ipv6NeighbourAdvertisement::setTargetAddress(const Ipv6Address& targetAddress)
{
    handleChange();
    this->targetAddress = targetAddress;
}

const Ipv6NdOptions& Ipv6NeighbourAdvertisement::getOptions() const
{
    return this->options;
}

void Ipv6NeighbourAdvertisement::setOptions(const Ipv6NdOptions& options)
{
    handleChange();
    this->options = options;
}

class Ipv6NeighbourAdvertisementDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_routerFlag,
        FIELD_solicitedFlag,
        FIELD_overrideFlag,
        FIELD_reserved,
        FIELD_targetAddress,
        FIELD_options,
    };
  public:
    Ipv6NeighbourAdvertisementDescriptor();
    virtual ~Ipv6NeighbourAdvertisementDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NeighbourAdvertisementDescriptor)

Ipv6NeighbourAdvertisementDescriptor::Ipv6NeighbourAdvertisementDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NeighbourAdvertisement)), "inet::Ipv6NdMessage")
{
    propertynames = nullptr;
}

Ipv6NeighbourAdvertisementDescriptor::~Ipv6NeighbourAdvertisementDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NeighbourAdvertisementDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NeighbourAdvertisement *>(obj)!=nullptr;
}

const char **Ipv6NeighbourAdvertisementDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NeighbourAdvertisementDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NeighbourAdvertisementDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int Ipv6NeighbourAdvertisementDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_routerFlag
        FD_ISEDITABLE,    // FIELD_solicitedFlag
        FD_ISEDITABLE,    // FIELD_overrideFlag
        FD_ISEDITABLE,    // FIELD_reserved
        0,    // FIELD_targetAddress
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_options
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6NeighbourAdvertisementDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "routerFlag",
        "solicitedFlag",
        "overrideFlag",
        "reserved",
        "targetAddress",
        "options",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int Ipv6NeighbourAdvertisementDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerFlag") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "solicitedFlag") == 0) return base+1;
    if (fieldName[0] == 'o' && strcmp(fieldName, "overrideFlag") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+3;
    if (fieldName[0] == 't' && strcmp(fieldName, "targetAddress") == 0) return base+4;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NeighbourAdvertisementDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_routerFlag
        "bool",    // FIELD_solicitedFlag
        "bool",    // FIELD_overrideFlag
        "uint32_t",    // FIELD_reserved
        "inet::Ipv6Address",    // FIELD_targetAddress
        "inet::Ipv6NdOptions",    // FIELD_options
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6NeighbourAdvertisementDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6NeighbourAdvertisementDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6NeighbourAdvertisementDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NeighbourAdvertisement *pp = (Ipv6NeighbourAdvertisement *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6NeighbourAdvertisementDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NeighbourAdvertisement *pp = (Ipv6NeighbourAdvertisement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6NeighbourAdvertisementDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NeighbourAdvertisement *pp = (Ipv6NeighbourAdvertisement *)object; (void)pp;
    switch (field) {
        case FIELD_routerFlag: return bool2string(pp->getRouterFlag());
        case FIELD_solicitedFlag: return bool2string(pp->getSolicitedFlag());
        case FIELD_overrideFlag: return bool2string(pp->getOverrideFlag());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_targetAddress: return pp->getTargetAddress().str();
        case FIELD_options: {std::stringstream out; out << pp->getOptions(); return out.str();}
        default: return "";
    }
}

bool Ipv6NeighbourAdvertisementDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NeighbourAdvertisement *pp = (Ipv6NeighbourAdvertisement *)object; (void)pp;
    switch (field) {
        case FIELD_routerFlag: pp->setRouterFlag(string2bool(value)); return true;
        case FIELD_solicitedFlag: pp->setSolicitedFlag(string2bool(value)); return true;
        case FIELD_overrideFlag: pp->setOverrideFlag(string2bool(value)); return true;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ipv6NeighbourAdvertisementDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(Ipv6NdOptions));
        default: return nullptr;
    };
}

void *Ipv6NeighbourAdvertisementDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NeighbourAdvertisement *pp = (Ipv6NeighbourAdvertisement *)object; (void)pp;
    switch (field) {
        case FIELD_targetAddress: return toVoidPtr(&pp->getTargetAddress()); break;
        case FIELD_options: return toVoidPtr(&pp->getOptions()); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6Redirect)

Ipv6Redirect::Ipv6Redirect() : ::inet::Ipv6NdMessage()
{
    this->setChunkLength(B(40));
    this->setType(ICMPv6_REDIRECT);

}

Ipv6Redirect::Ipv6Redirect(const Ipv6Redirect& other) : ::inet::Ipv6NdMessage(other)
{
    copy(other);
}

Ipv6Redirect::~Ipv6Redirect()
{
}

Ipv6Redirect& Ipv6Redirect::operator=(const Ipv6Redirect& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6NdMessage::operator=(other);
    copy(other);
    return *this;
}

void Ipv6Redirect::copy(const Ipv6Redirect& other)
{
    this->targetAddress = other.targetAddress;
    this->destinationAddress = other.destinationAddress;
    this->options = other.options;
}

void Ipv6Redirect::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6NdMessage::parsimPack(b);
    doParsimPacking(b,this->targetAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->options);
}

void Ipv6Redirect::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6NdMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->targetAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->options);
}

const Ipv6Address& Ipv6Redirect::getTargetAddress() const
{
    return this->targetAddress;
}

void Ipv6Redirect::setTargetAddress(const Ipv6Address& targetAddress)
{
    handleChange();
    this->targetAddress = targetAddress;
}

const Ipv6Address& Ipv6Redirect::getDestinationAddress() const
{
    return this->destinationAddress;
}

void Ipv6Redirect::setDestinationAddress(const Ipv6Address& destinationAddress)
{
    handleChange();
    this->destinationAddress = destinationAddress;
}

const Ipv6NdOptions& Ipv6Redirect::getOptions() const
{
    return this->options;
}

void Ipv6Redirect::setOptions(const Ipv6NdOptions& options)
{
    handleChange();
    this->options = options;
}

class Ipv6RedirectDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_targetAddress,
        FIELD_destinationAddress,
        FIELD_options,
    };
  public:
    Ipv6RedirectDescriptor();
    virtual ~Ipv6RedirectDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6RedirectDescriptor)

Ipv6RedirectDescriptor::Ipv6RedirectDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6Redirect)), "inet::Ipv6NdMessage")
{
    propertynames = nullptr;
}

Ipv6RedirectDescriptor::~Ipv6RedirectDescriptor()
{
    delete[] propertynames;
}

bool Ipv6RedirectDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6Redirect *>(obj)!=nullptr;
}

const char **Ipv6RedirectDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6RedirectDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6RedirectDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ipv6RedirectDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_targetAddress
        0,    // FIELD_destinationAddress
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_options
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6RedirectDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "targetAddress",
        "destinationAddress",
        "options",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ipv6RedirectDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "targetAddress") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationAddress") == 0) return base+1;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6RedirectDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv6Address",    // FIELD_targetAddress
        "inet::Ipv6Address",    // FIELD_destinationAddress
        "inet::Ipv6NdOptions",    // FIELD_options
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6RedirectDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6RedirectDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6RedirectDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6Redirect *pp = (Ipv6Redirect *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6RedirectDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6Redirect *pp = (Ipv6Redirect *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6RedirectDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6Redirect *pp = (Ipv6Redirect *)object; (void)pp;
    switch (field) {
        case FIELD_targetAddress: return pp->getTargetAddress().str();
        case FIELD_destinationAddress: return pp->getDestinationAddress().str();
        case FIELD_options: {std::stringstream out; out << pp->getOptions(); return out.str();}
        default: return "";
    }
}

bool Ipv6RedirectDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6Redirect *pp = (Ipv6Redirect *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6RedirectDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(Ipv6NdOptions));
        default: return nullptr;
    };
}

void *Ipv6RedirectDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6Redirect *pp = (Ipv6Redirect *)object; (void)pp;
    switch (field) {
        case FIELD_targetAddress: return toVoidPtr(&pp->getTargetAddress()); break;
        case FIELD_destinationAddress: return toVoidPtr(&pp->getDestinationAddress()); break;
        case FIELD_options: return toVoidPtr(&pp->getOptions()); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6NdControlInfo)

Ipv6NdControlInfo::Ipv6NdControlInfo() : ::omnetpp::cObject()
{
}

Ipv6NdControlInfo::Ipv6NdControlInfo(const Ipv6NdControlInfo& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ipv6NdControlInfo::~Ipv6NdControlInfo()
{
}

Ipv6NdControlInfo& Ipv6NdControlInfo::operator=(const Ipv6NdControlInfo& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ipv6NdControlInfo::copy(const Ipv6NdControlInfo& other)
{
    this->nextHop = other.nextHop;
    this->interfaceId = other.interfaceId;
    this->fromHL = other.fromHL;
}

void Ipv6NdControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->nextHop);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->fromHL);
}

void Ipv6NdControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->nextHop);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->fromHL);
}

const Ipv6Address& Ipv6NdControlInfo::getNextHop() const
{
    return this->nextHop;
}

void Ipv6NdControlInfo::setNextHop(const Ipv6Address& nextHop)
{
    this->nextHop = nextHop;
}

int Ipv6NdControlInfo::getInterfaceId() const
{
    return this->interfaceId;
}

void Ipv6NdControlInfo::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

bool Ipv6NdControlInfo::getFromHL() const
{
    return this->fromHL;
}

void Ipv6NdControlInfo::setFromHL(bool fromHL)
{
    this->fromHL = fromHL;
}

class Ipv6NdControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_nextHop,
        FIELD_interfaceId,
        FIELD_fromHL,
    };
  public:
    Ipv6NdControlInfoDescriptor();
    virtual ~Ipv6NdControlInfoDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ipv6NdControlInfoDescriptor)

Ipv6NdControlInfoDescriptor::Ipv6NdControlInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6NdControlInfo)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ipv6NdControlInfoDescriptor::~Ipv6NdControlInfoDescriptor()
{
    delete[] propertynames;
}

bool Ipv6NdControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6NdControlInfo *>(obj)!=nullptr;
}

const char **Ipv6NdControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6NdControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6NdControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ipv6NdControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_nextHop
        FD_ISEDITABLE,    // FIELD_interfaceId
        FD_ISEDITABLE,    // FIELD_fromHL
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6NdControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nextHop",
        "interfaceId",
        "fromHL",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ipv6NdControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextHop") == 0) return base+0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interfaceId") == 0) return base+1;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fromHL") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6NdControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv6Address",    // FIELD_nextHop
        "int",    // FIELD_interfaceId
        "bool",    // FIELD_fromHL
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6NdControlInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ipv6NdControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ipv6NdControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdControlInfo *pp = (Ipv6NdControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6NdControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdControlInfo *pp = (Ipv6NdControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6NdControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdControlInfo *pp = (Ipv6NdControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_nextHop: return pp->getNextHop().str();
        case FIELD_interfaceId: return long2string(pp->getInterfaceId());
        case FIELD_fromHL: return bool2string(pp->getFromHL());
        default: return "";
    }
}

bool Ipv6NdControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdControlInfo *pp = (Ipv6NdControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: pp->setInterfaceId(string2long(value)); return true;
        case FIELD_fromHL: pp->setFromHL(string2bool(value)); return true;
        default: return false;
    }
}

const char *Ipv6NdControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ipv6NdControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6NdControlInfo *pp = (Ipv6NdControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_nextHop: return toVoidPtr(&pp->getNextHop()); break;
        default: return nullptr;
    }
}

} // namespace inet


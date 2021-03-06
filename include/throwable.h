/**
 *  Throwable
 *
 *  Base class for Php Exceptions.
 *
 *  @author Jasper van Eck <jasper.vaneck@copernica.com>
 *  @copyright 2013 - 2019 Copernica BV
 */
#include <exception>

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  Class definition
 */
class PHPCPP_EXPORT Throwable : public std::exception
{
private:
    /**
     *  The exception message
     *  @var    char*
     */
    std::string _message;

    /**
     *  The PHP exception code
     *  @var    int
     */
    int _code;

    /**
     *  Has this exception been processed by native C++ code?
     *  @var    bool
     */
    bool _processed = false;

protected:
    /**
     *  Constructor
     *  @param  &string
     */
    Throwable(const std::string &message, int code = 0) : std::exception(), _message(message), _code(code) {}

public:
    /**
     *  Destructor
     */
    virtual ~Throwable() throw() {}

    /**
     *  Overridden what method
     *  @return const char *
     */
    virtual const char *what() const _NOEXCEPT override
    {
        return _message.c_str();
    }

    /**
     *  Returns the message of the exception.
     *  @return &string
     */
    const std::string &message() const throw()
    {
        return _message;
    }

    /**
     *  Is this a native exception (one that was thrown from C++ code)
     *  @return bool
     */
    virtual bool native() const
    {
        // yes, it is native
        return true;
    }

    /**
     *  Report this error as a fatal error
     *  @return bool
     */
    virtual bool report() const
    {
        // this is not done here
        return false;
    }
};

/**
 *  End of namespace
 */
}

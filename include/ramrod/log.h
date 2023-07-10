#ifndef RAMROD_LOG_H
#define RAMROD_LOG_H

#include "ramrod/log_ostream.h"

#include "ramrod/log_attention.h"
#include "ramrod/log_error.h"
#include "ramrod/log_format.h"
#include "ramrod/log_good.h"
#include "ramrod/log_perror.h"
#include "ramrod/log_types.h"
#include "ramrod/log_warning.h"


namespace ramrod {
  class endl_stream
  {
  public:
    endl_stream() = default;

    endl_stream &operator()();

    friend std::ostream &operator<<(std::ostream &output, endl_stream &);
  };

  class flush_stream
  {
  public:
    flush_stream() = default;

    flush_stream &operator()();

    friend std::ostream &operator<<(std::ostream &output, flush_stream &);
  };

  class log_system : public base_ostream
  {
  public:
    log_system() = default;
  };

  class clean_stream
  {
  public:
    clean_stream() = default;

    const char *ansi();
    const char *ansi() const;

    clean_stream &operator()();

    log_system &operator<<(log_system &output);

    friend std::ostream &operator<<(std::ostream &output, clean_stream &);
  };

  inline static clean_stream clean;
  inline static endl_stream endl;
  inline static flush_stream flush;
  inline static log_system log;

} // namespace ramrod

namespace rr = ramrod;

#endif // RAMROD_LOG_H

#include <pqxx/internal/callgate.hxx>

namespace pqxx::internal::gate
{
class PQXX_PRIVATE result_creation : callgate<const result>
{
  friend class pqxx::connection;
  friend class pqxx::pipeline;

  result_creation(reference x) : super(x) {}

  static result create(
    internal::pq::PGresult *rhs, std::shared_ptr<std::string> query, encoding_group enc)
  {
    return result(rhs, query, enc);
  }

  void check_status() const { return home().check_status(); }
};
} // namespace pqxx::internal::gate

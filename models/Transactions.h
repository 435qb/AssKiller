/**
 *
 *  Transactions.h
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#include <drogon/orm/BaseBuilder.h>
#ifdef __cpp_impl_coroutine
#include <drogon/orm/CoroMapper.h>
#endif
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

namespace drogon
{
namespace orm
{
class DbClient;
using DbClientPtr = std::shared_ptr<DbClient>;
}
}
namespace drogon_model
{
namespace test
{
class User;
class Usergroup;

class Transactions
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _txuuid;
        static const std::string _time;
        static const std::string _useruuid;
        static const std::string _guuid;
        static const std::string _count;
    };

    const static int primaryKeyNumber;
    const static std::string tableName;
    const static bool hasPrimaryKey;
    const static std::string primaryKeyName;
    using PrimaryKeyType = int32_t;
    const PrimaryKeyType &getPrimaryKey() const;

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names,
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all
     * columns by an asterisk), please set the offset to -1.
     */
    explicit Transactions(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Transactions(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    Transactions(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Transactions() = default;

    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err);
    static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    static bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson,
                          std::string &err,
                          bool isForCreation);

    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const int32_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getId() const noexcept;
    ///Set the value of the column id
    void setId(const int32_t &pId) noexcept;

    /**  For column txuuid  */
    ///Get the value of the column txuuid, returns the default value if the column is null
    const std::string &getValueOfTxuuid() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getTxuuid() const noexcept;
    ///Set the value of the column txuuid
    void setTxuuid(const std::string &pTxuuid) noexcept;
    void setTxuuid(std::string &&pTxuuid) noexcept;

    /**  For column time  */
    ///Get the value of the column time, returns the default value if the column is null
    const ::trantor::Date &getValueOfTime() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getTime() const noexcept;
    ///Set the value of the column time
    void setTime(const ::trantor::Date &pTime) noexcept;

    /**  For column useruuid  */
    ///Get the value of the column useruuid, returns the default value if the column is null
    const std::string &getValueOfUseruuid() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getUseruuid() const noexcept;
    ///Set the value of the column useruuid
    void setUseruuid(const std::string &pUseruuid) noexcept;
    void setUseruuid(std::string &&pUseruuid) noexcept;

    /**  For column guuid  */
    ///Get the value of the column guuid, returns the default value if the column is null
    const std::string &getValueOfGuuid() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getGuuid() const noexcept;
    ///Set the value of the column guuid
    void setGuuid(const std::string &pGuuid) noexcept;
    void setGuuid(std::string &&pGuuid) noexcept;

    /**  For column count  */
    ///Get the value of the column count, returns the default value if the column is null
    const int32_t &getValueOfCount() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getCount() const noexcept;
    ///Set the value of the column count
    void setCount(const int32_t &pCount) noexcept;


    static size_t getColumnNumber() noexcept {  return 6;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
    User getUser(const drogon::orm::DbClientPtr &clientPtr) const;
    void getUser(const drogon::orm::DbClientPtr &clientPtr,
                 const std::function<void(User)> &rcb,
                 const drogon::orm::ExceptionCallback &ecb) const;
    Usergroup getUsergroup(const drogon::orm::DbClientPtr &clientPtr) const;
    void getUsergroup(const drogon::orm::DbClientPtr &clientPtr,
                      const std::function<void(Usergroup)> &rcb,
                      const drogon::orm::ExceptionCallback &ecb) const;
  private:
    friend drogon::orm::Mapper<Transactions>;
    friend drogon::orm::BaseBuilder<Transactions, true, true>;
    friend drogon::orm::BaseBuilder<Transactions, true, false>;
    friend drogon::orm::BaseBuilder<Transactions, false, true>;
    friend drogon::orm::BaseBuilder<Transactions, false, false>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<Transactions>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> id_;
    std::shared_ptr<std::string> txuuid_;
    std::shared_ptr<::trantor::Date> time_;
    std::shared_ptr<std::string> useruuid_;
    std::shared_ptr<std::string> guuid_;
    std::shared_ptr<int32_t> count_;
    struct MetaData
    {
        const std::string colName_;
        const std::string colType_;
        const std::string colDatabaseType_;
        const ssize_t colLength_;
        const bool isAutoVal_;
        const bool isPrimaryKey_;
        const bool notNull_;
    };
    static const std::vector<MetaData> metaData_;
    bool dirtyFlag_[6]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where id = ?";
        return sql;
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where id = ?";
        return sql;
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
            sql += "id,";
            ++parametersCount;
        if(dirtyFlag_[1])
        {
            sql += "txuuid,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "time,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "useruuid,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "guuid,";
            ++parametersCount;
        }
        if(dirtyFlag_[5])
        {
            sql += "count,";
            ++parametersCount;
        }
        needSelection=true;
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";

        sql +="default,";
        if(dirtyFlag_[1])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[2])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[3])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[4])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[5])
        {
            sql.append("?,");

        }
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        sql.append(1, ')');
        LOG_TRACE << sql;
        return sql;
    }
};
} // namespace test
} // namespace drogon_model

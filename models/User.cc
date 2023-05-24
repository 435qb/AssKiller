/**
 *
 *  User.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "User.h"
#include "Transactions.h"
#include "Usergroup.h"
#include "UsergroupUser.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::test;

const std::string User::Cols::_account = "account";
const std::string User::Cols::_password = "password";
const std::string User::Cols::_uuid = "uuid";
const std::string User::primaryKeyName = "uuid";
const bool User::hasPrimaryKey = true;
const std::string User::tableName = "user";

const std::vector<typename User::MetaData> User::metaData_={
{"account","std::string","varchar(100)",100,0,0,1},
{"password","std::string","varchar(100)",100,0,0,1},
{"uuid","std::string","varchar(100)",100,0,1,1}
};
const std::string &User::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
User::User(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["account"].isNull())
        {
            account_=std::make_shared<std::string>(r["account"].as<std::string>());
        }
        if(!r["password"].isNull())
        {
            password_=std::make_shared<std::string>(r["password"].as<std::string>());
        }
        if(!r["uuid"].isNull())
        {
            uuid_=std::make_shared<std::string>(r["uuid"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 3 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            account_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            password_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            uuid_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

User::User(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            account_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            password_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
}

User::User(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("account"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["account"].isNull())
        {
            account_=std::make_shared<std::string>(pJson["account"].asString());
        }
    }
    if(pJson.isMember("password"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["password"].isNull())
        {
            password_=std::make_shared<std::string>(pJson["password"].asString());
        }
    }
    if(pJson.isMember("uuid"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["uuid"].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson["uuid"].asString());
        }
    }
}

void User::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            account_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            password_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
}

void User::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("account"))
    {
        dirtyFlag_[0] = true;
        if(!pJson["account"].isNull())
        {
            account_=std::make_shared<std::string>(pJson["account"].asString());
        }
    }
    if(pJson.isMember("password"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["password"].isNull())
        {
            password_=std::make_shared<std::string>(pJson["password"].asString());
        }
    }
    if(pJson.isMember("uuid"))
    {
        if(!pJson["uuid"].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson["uuid"].asString());
        }
    }
}

const std::string &User::getValueOfAccount() const noexcept
{
    const static std::string defaultValue = std::string();
    if(account_)
        return *account_;
    return defaultValue;
}
const std::shared_ptr<std::string> &User::getAccount() const noexcept
{
    return account_;
}
void User::setAccount(const std::string &pAccount) noexcept
{
    account_ = std::make_shared<std::string>(pAccount);
    dirtyFlag_[0] = true;
}
void User::setAccount(std::string &&pAccount) noexcept
{
    account_ = std::make_shared<std::string>(std::move(pAccount));
    dirtyFlag_[0] = true;
}

const std::string &User::getValueOfPassword() const noexcept
{
    const static std::string defaultValue = std::string();
    if(password_)
        return *password_;
    return defaultValue;
}
const std::shared_ptr<std::string> &User::getPassword() const noexcept
{
    return password_;
}
void User::setPassword(const std::string &pPassword) noexcept
{
    password_ = std::make_shared<std::string>(pPassword);
    dirtyFlag_[1] = true;
}
void User::setPassword(std::string &&pPassword) noexcept
{
    password_ = std::make_shared<std::string>(std::move(pPassword));
    dirtyFlag_[1] = true;
}

const std::string &User::getValueOfUuid() const noexcept
{
    const static std::string defaultValue = std::string();
    if(uuid_)
        return *uuid_;
    return defaultValue;
}
const std::shared_ptr<std::string> &User::getUuid() const noexcept
{
    return uuid_;
}
void User::setUuid(const std::string &pUuid) noexcept
{
    uuid_ = std::make_shared<std::string>(pUuid);
    dirtyFlag_[2] = true;
}
void User::setUuid(std::string &&pUuid) noexcept
{
    uuid_ = std::make_shared<std::string>(std::move(pUuid));
    dirtyFlag_[2] = true;
}
const typename User::PrimaryKeyType & User::getPrimaryKey() const
{
    assert(uuid_);
    return *uuid_;
}

void User::updateId(const uint64_t id)
{
}

const std::vector<std::string> &User::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "account",
        "password",
        "uuid"
    };
    return inCols;
}

void User::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getAccount())
        {
            binder << getValueOfAccount();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getPassword())
        {
            binder << getValueOfPassword();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getUuid())
        {
            binder << getValueOfUuid();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> User::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[0])
    {
        ret.push_back(getColumnName(0));
    }
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    return ret;
}

void User::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getAccount())
        {
            binder << getValueOfAccount();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getPassword())
        {
            binder << getValueOfPassword();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getUuid())
        {
            binder << getValueOfUuid();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value User::toJson() const
{
    Json::Value ret;
    if(getAccount())
    {
        ret["account"]=getValueOfAccount();
    }
    else
    {
        ret["account"]=Json::Value();
    }
    if(getPassword())
    {
        ret["password"]=getValueOfPassword();
    }
    else
    {
        ret["password"]=Json::Value();
    }
    if(getUuid())
    {
        ret["uuid"]=getValueOfUuid();
    }
    else
    {
        ret["uuid"]=Json::Value();
    }
    return ret;
}

Json::Value User::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 3)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getAccount())
            {
                ret[pMasqueradingVector[0]]=getValueOfAccount();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getPassword())
            {
                ret[pMasqueradingVector[1]]=getValueOfPassword();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getUuid())
            {
                ret[pMasqueradingVector[2]]=getValueOfUuid();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getAccount())
    {
        ret["account"]=getValueOfAccount();
    }
    else
    {
        ret["account"]=Json::Value();
    }
    if(getPassword())
    {
        ret["password"]=getValueOfPassword();
    }
    else
    {
        ret["password"]=Json::Value();
    }
    if(getUuid())
    {
        ret["uuid"]=getValueOfUuid();
    }
    else
    {
        ret["uuid"]=Json::Value();
    }
    return ret;
}

bool User::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("account"))
    {
        if(!validJsonOfField(0, "account", pJson["account"], err, true))
            return false;
    }
    else
    {
        err="The account column cannot be null";
        return false;
    }
    if(pJson.isMember("password"))
    {
        if(!validJsonOfField(1, "password", pJson["password"], err, true))
            return false;
    }
    else
    {
        err="The password column cannot be null";
        return false;
    }
    if(pJson.isMember("uuid"))
    {
        if(!validJsonOfField(2, "uuid", pJson["uuid"], err, true))
            return false;
    }
    else
    {
        err="The uuid column cannot be null";
        return false;
    }
    return true;
}
bool User::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                              const std::vector<std::string> &pMasqueradingVector,
                                              std::string &err)
{
    if(pMasqueradingVector.size() != 3)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[0] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[2] + " column cannot be null";
            return false;
        }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool User::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("account"))
    {
        if(!validJsonOfField(0, "account", pJson["account"], err, false))
            return false;
    }
    if(pJson.isMember("password"))
    {
        if(!validJsonOfField(1, "password", pJson["password"], err, false))
            return false;
    }
    if(pJson.isMember("uuid"))
    {
        if(!validJsonOfField(2, "uuid", pJson["uuid"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    return true;
}
bool User::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector,
                                            std::string &err)
{
    if(pMasqueradingVector.size() != 3)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool User::validJsonOfField(size_t index,
                            const std::string &fieldName,
                            const Json::Value &pJson,
                            std::string &err,
                            bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 100)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 100)";
                return false;
            }

            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 100)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 100)";
                return false;
            }

            break;
        case 2:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 100)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 100)";
                return false;
            }

            break;
        default:
            err="Internal error in the server";
            return false;
    }
    return true;
}
std::vector<Transactions> User::getTransactions(const drogon::orm::DbClientPtr &clientPtr) const {
    std::shared_ptr<std::promise<std::vector<Transactions>>> pro(new std::promise<std::vector<Transactions>>);
    std::future<std::vector<Transactions>> f = pro->get_future();
    getTransactions(clientPtr, [&pro] (std::vector<Transactions> result) {
        try {
            pro->set_value(result);
        }
        catch (...) {
            pro->set_exception(std::current_exception());
        }
    }, [&pro] (const DrogonDbException &err) {
        pro->set_exception(std::make_exception_ptr(err));
    });
    return f.get();
}
void User::getTransactions(const DbClientPtr &clientPtr,
                           const std::function<void(std::vector<Transactions>)> &rcb,
                           const ExceptionCallback &ecb) const
{
    const static std::string sql = "select * from transactions where useruuid = ?";
    *clientPtr << sql
               << *uuid_
               >> [rcb = std::move(rcb)](const Result &r){
                   std::vector<Transactions> ret;
                   ret.reserve(r.size());
                   for (auto const &row : r)
                   {
                       ret.emplace_back(Transactions(row));
                   }
                   rcb(ret);
               }
               >> ecb;
}
std::vector<std::pair<Usergroup,UsergroupUser>> User::getUsergroup(const drogon::orm::DbClientPtr &clientPtr) const {
    std::shared_ptr<std::promise<std::vector<std::pair<Usergroup,UsergroupUser>>>> pro(new std::promise<std::vector<std::pair<Usergroup,UsergroupUser>>>);
    std::future<std::vector<std::pair<Usergroup,UsergroupUser>>> f = pro->get_future();
    getUsergroup(clientPtr, [&pro] (std::vector<std::pair<Usergroup,UsergroupUser>> result) {
        try {
            pro->set_value(result);
        }
        catch (...) {
            pro->set_exception(std::current_exception());
        }
    }, [&pro] (const DrogonDbException &err) {
        pro->set_exception(std::make_exception_ptr(err));
    });
    return f.get();
}
void User::getUsergroup(const DbClientPtr &clientPtr,
                        const std::function<void(std::vector<std::pair<Usergroup,UsergroupUser>>)> &rcb,
                        const ExceptionCallback &ecb) const
{
    const static std::string sql = "select * from usergroup,usergroup_user where usergroup_user.useruuid = ? and usergroup_user.guuid = usergroup.uuid";
    *clientPtr << sql
               << *uuid_
               >> [rcb = std::move(rcb)](const Result &r){
                   std::vector<std::pair<Usergroup,UsergroupUser>> ret;
                   ret.reserve(r.size());
                   for (auto const &row : r)
                   {
                       ret.emplace_back(std::pair<Usergroup,UsergroupUser>(
                           Usergroup(row),UsergroupUser(row,Usergroup::getColumnNumber())));
                   }
                   rcb(ret);
               }
               >> ecb;
}

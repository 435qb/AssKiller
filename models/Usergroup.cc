/**
 *
 *  Usergroup.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Usergroup.h"
#include "Transactions.h"
#include "User.h"
#include "UsergroupUser.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::test;

const std::string Usergroup::Cols::_uuid = "uuid";
const std::string Usergroup::Cols::_is_deleted = "is_deleted";
const std::string Usergroup::Cols::_nextuuid = "nextuuid";
const std::string Usergroup::Cols::_count = "count";
const std::string Usergroup::primaryKeyName = "uuid";
const bool Usergroup::hasPrimaryKey = true;
const std::string Usergroup::tableName = "usergroup";

const std::vector<typename Usergroup::MetaData> Usergroup::metaData_={
{"uuid","std::string","varchar(100)",100,0,1,1},
{"is_deleted","int8_t","tinyint(1)",1,0,0,1},
{"nextuuid","std::string","varchar(100)",100,0,0,1},
{"count","int32_t","int(11)",4,0,0,1}
};
const std::string &Usergroup::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Usergroup::Usergroup(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["uuid"].isNull())
        {
            uuid_=std::make_shared<std::string>(r["uuid"].as<std::string>());
        }
        if(!r["is_deleted"].isNull())
        {
            isDeleted_=std::make_shared<int8_t>(r["is_deleted"].as<int8_t>());
        }
        if(!r["nextuuid"].isNull())
        {
            nextuuid_=std::make_shared<std::string>(r["nextuuid"].as<std::string>());
        }
        if(!r["count"].isNull())
        {
            count_=std::make_shared<int32_t>(r["count"].as<int32_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 4 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            uuid_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            isDeleted_=std::make_shared<int8_t>(r[index].as<int8_t>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            nextuuid_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            count_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
    }

}

Usergroup::Usergroup(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            isDeleted_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            nextuuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            count_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

Usergroup::Usergroup(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("uuid"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["uuid"].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson["uuid"].asString());
        }
    }
    if(pJson.isMember("is_deleted"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["is_deleted"].isNull())
        {
            isDeleted_=std::make_shared<int8_t>((int8_t)pJson["is_deleted"].asInt64());
        }
    }
    if(pJson.isMember("nextuuid"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["nextuuid"].isNull())
        {
            nextuuid_=std::make_shared<std::string>(pJson["nextuuid"].asString());
        }
    }
    if(pJson.isMember("count"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["count"].isNull())
        {
            count_=std::make_shared<int32_t>((int32_t)pJson["count"].asInt64());
        }
    }
}

void Usergroup::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            isDeleted_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            nextuuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            count_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

void Usergroup::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("uuid"))
    {
        if(!pJson["uuid"].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson["uuid"].asString());
        }
    }
    if(pJson.isMember("is_deleted"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["is_deleted"].isNull())
        {
            isDeleted_=std::make_shared<int8_t>((int8_t)pJson["is_deleted"].asInt64());
        }
    }
    if(pJson.isMember("nextuuid"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["nextuuid"].isNull())
        {
            nextuuid_=std::make_shared<std::string>(pJson["nextuuid"].asString());
        }
    }
    if(pJson.isMember("count"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["count"].isNull())
        {
            count_=std::make_shared<int32_t>((int32_t)pJson["count"].asInt64());
        }
    }
}

const std::string &Usergroup::getValueOfUuid() const noexcept
{
    const static std::string defaultValue = std::string();
    if(uuid_)
        return *uuid_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Usergroup::getUuid() const noexcept
{
    return uuid_;
}
void Usergroup::setUuid(const std::string &pUuid) noexcept
{
    uuid_ = std::make_shared<std::string>(pUuid);
    dirtyFlag_[0] = true;
}
void Usergroup::setUuid(std::string &&pUuid) noexcept
{
    uuid_ = std::make_shared<std::string>(std::move(pUuid));
    dirtyFlag_[0] = true;
}
const typename Usergroup::PrimaryKeyType & Usergroup::getPrimaryKey() const
{
    assert(uuid_);
    return *uuid_;
}

const int8_t &Usergroup::getValueOfIsDeleted() const noexcept
{
    const static int8_t defaultValue = int8_t();
    if(isDeleted_)
        return *isDeleted_;
    return defaultValue;
}
const std::shared_ptr<int8_t> &Usergroup::getIsDeleted() const noexcept
{
    return isDeleted_;
}
void Usergroup::setIsDeleted(const int8_t &pIsDeleted) noexcept
{
    isDeleted_ = std::make_shared<int8_t>(pIsDeleted);
    dirtyFlag_[1] = true;
}

const std::string &Usergroup::getValueOfNextuuid() const noexcept
{
    const static std::string defaultValue = std::string();
    if(nextuuid_)
        return *nextuuid_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Usergroup::getNextuuid() const noexcept
{
    return nextuuid_;
}
void Usergroup::setNextuuid(const std::string &pNextuuid) noexcept
{
    nextuuid_ = std::make_shared<std::string>(pNextuuid);
    dirtyFlag_[2] = true;
}
void Usergroup::setNextuuid(std::string &&pNextuuid) noexcept
{
    nextuuid_ = std::make_shared<std::string>(std::move(pNextuuid));
    dirtyFlag_[2] = true;
}

const int32_t &Usergroup::getValueOfCount() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(count_)
        return *count_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Usergroup::getCount() const noexcept
{
    return count_;
}
void Usergroup::setCount(const int32_t &pCount) noexcept
{
    count_ = std::make_shared<int32_t>(pCount);
    dirtyFlag_[3] = true;
}

void Usergroup::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Usergroup::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "uuid",
        "is_deleted",
        "nextuuid",
        "count"
    };
    return inCols;
}

void Usergroup::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
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
    if(dirtyFlag_[1])
    {
        if(getIsDeleted())
        {
            binder << getValueOfIsDeleted();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getNextuuid())
        {
            binder << getValueOfNextuuid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getCount())
        {
            binder << getValueOfCount();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Usergroup::updateColumns() const
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
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    return ret;
}

void Usergroup::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
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
    if(dirtyFlag_[1])
    {
        if(getIsDeleted())
        {
            binder << getValueOfIsDeleted();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getNextuuid())
        {
            binder << getValueOfNextuuid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getCount())
        {
            binder << getValueOfCount();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Usergroup::toJson() const
{
    Json::Value ret;
    if(getUuid())
    {
        ret["uuid"]=getValueOfUuid();
    }
    else
    {
        ret["uuid"]=Json::Value();
    }
    if(getIsDeleted())
    {
        ret["is_deleted"]=getValueOfIsDeleted();
    }
    else
    {
        ret["is_deleted"]=Json::Value();
    }
    if(getNextuuid())
    {
        ret["nextuuid"]=getValueOfNextuuid();
    }
    else
    {
        ret["nextuuid"]=Json::Value();
    }
    if(getCount())
    {
        ret["count"]=getValueOfCount();
    }
    else
    {
        ret["count"]=Json::Value();
    }
    return ret;
}

Json::Value Usergroup::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 4)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getUuid())
            {
                ret[pMasqueradingVector[0]]=getValueOfUuid();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getIsDeleted())
            {
                ret[pMasqueradingVector[1]]=getValueOfIsDeleted();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getNextuuid())
            {
                ret[pMasqueradingVector[2]]=getValueOfNextuuid();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getCount())
            {
                ret[pMasqueradingVector[3]]=getValueOfCount();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getUuid())
    {
        ret["uuid"]=getValueOfUuid();
    }
    else
    {
        ret["uuid"]=Json::Value();
    }
    if(getIsDeleted())
    {
        ret["is_deleted"]=getValueOfIsDeleted();
    }
    else
    {
        ret["is_deleted"]=Json::Value();
    }
    if(getNextuuid())
    {
        ret["nextuuid"]=getValueOfNextuuid();
    }
    else
    {
        ret["nextuuid"]=Json::Value();
    }
    if(getCount())
    {
        ret["count"]=getValueOfCount();
    }
    else
    {
        ret["count"]=Json::Value();
    }
    return ret;
}

bool Usergroup::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("uuid"))
    {
        if(!validJsonOfField(0, "uuid", pJson["uuid"], err, true))
            return false;
    }
    else
    {
        err="The uuid column cannot be null";
        return false;
    }
    if(pJson.isMember("is_deleted"))
    {
        if(!validJsonOfField(1, "is_deleted", pJson["is_deleted"], err, true))
            return false;
    }
    if(pJson.isMember("nextuuid"))
    {
        if(!validJsonOfField(2, "nextuuid", pJson["nextuuid"], err, true))
            return false;
    }
    else
    {
        err="The nextuuid column cannot be null";
        return false;
    }
    if(pJson.isMember("count"))
    {
        if(!validJsonOfField(3, "count", pJson["count"], err, true))
            return false;
    }
    return true;
}
bool Usergroup::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                   const std::vector<std::string> &pMasqueradingVector,
                                                   std::string &err)
{
    if(pMasqueradingVector.size() != 4)
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
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
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
bool Usergroup::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("uuid"))
    {
        if(!validJsonOfField(0, "uuid", pJson["uuid"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("is_deleted"))
    {
        if(!validJsonOfField(1, "is_deleted", pJson["is_deleted"], err, false))
            return false;
    }
    if(pJson.isMember("nextuuid"))
    {
        if(!validJsonOfField(2, "nextuuid", pJson["nextuuid"], err, false))
            return false;
    }
    if(pJson.isMember("count"))
    {
        if(!validJsonOfField(3, "count", pJson["count"], err, false))
            return false;
    }
    return true;
}
bool Usergroup::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                 const std::vector<std::string> &pMasqueradingVector,
                                                 std::string &err)
{
    if(pMasqueradingVector.size() != 4)
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
    else
    {
        err = "The value of primary key must be set in the json object for update";
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
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
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
bool Usergroup::validJsonOfField(size_t index,
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
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
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
        case 3:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
    }
    return true;
}
std::vector<Transactions> Usergroup::getTransactions(const drogon::orm::DbClientPtr &clientPtr) const {
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
void Usergroup::getTransactions(const DbClientPtr &clientPtr,
                                const std::function<void(std::vector<Transactions>)> &rcb,
                                const ExceptionCallback &ecb) const
{
    const static std::string sql = "select * from transactions where guuid = ?";
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
std::vector<std::pair<User,UsergroupUser>> Usergroup::getUser(const drogon::orm::DbClientPtr &clientPtr) const {
    std::shared_ptr<std::promise<std::vector<std::pair<User,UsergroupUser>>>> pro(new std::promise<std::vector<std::pair<User,UsergroupUser>>>);
    std::future<std::vector<std::pair<User,UsergroupUser>>> f = pro->get_future();
    getUser(clientPtr, [&pro] (std::vector<std::pair<User,UsergroupUser>> result) {
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
void Usergroup::getUser(const DbClientPtr &clientPtr,
                        const std::function<void(std::vector<std::pair<User,UsergroupUser>>)> &rcb,
                        const ExceptionCallback &ecb) const
{
    const static std::string sql = "select * from user,usergroup_user where usergroup_user.guuid = ? and usergroup_user.useruuid = user.uuid";
    *clientPtr << sql
               << *uuid_
               >> [rcb = std::move(rcb)](const Result &r){
                   std::vector<std::pair<User,UsergroupUser>> ret;
                   ret.reserve(r.size());
                   for (auto const &row : r)
                   {
                       ret.emplace_back(std::pair<User,UsergroupUser>(
                           User(row),UsergroupUser(row,User::getColumnNumber())));
                   }
                   rcb(ret);
               }
               >> ecb;
}

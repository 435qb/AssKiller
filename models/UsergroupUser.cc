/**
 *
 *  UsergroupUser.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "UsergroupUser.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::test;

const std::string UsergroupUser::Cols::_guuid = "guuid";
const std::string UsergroupUser::Cols::_useruuid = "useruuid";
const std::string UsergroupUser::Cols::_index = "index";
const std::string UsergroupUser::primaryKeyName = "";
const bool UsergroupUser::hasPrimaryKey = false;
const std::string UsergroupUser::tableName = "usergroup_user";

const std::vector<typename UsergroupUser::MetaData> UsergroupUser::metaData_={
{"guuid","std::string","varchar(100)",100,0,0,1},
{"useruuid","std::string","varchar(100)",100,0,0,1},
{"index","int16_t","smallint(6)",2,0,0,1}
};
const std::string &UsergroupUser::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
UsergroupUser::UsergroupUser(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["guuid"].isNull())
        {
            guuid_=std::make_shared<std::string>(r["guuid"].as<std::string>());
        }
        if(!r["useruuid"].isNull())
        {
            useruuid_=std::make_shared<std::string>(r["useruuid"].as<std::string>());
        }
        if(!r["index"].isNull())
        {
            index_=std::make_shared<int16_t>(r["index"].as<int16_t>());
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
            guuid_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            useruuid_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            index_=std::make_shared<int16_t>(r[index].as<int16_t>());
        }
    }

}

UsergroupUser::UsergroupUser(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
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
            guuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            useruuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            index_=std::make_shared<int16_t>((int16_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
}

UsergroupUser::UsergroupUser(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("guuid"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["guuid"].isNull())
        {
            guuid_=std::make_shared<std::string>(pJson["guuid"].asString());
        }
    }
    if(pJson.isMember("useruuid"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["useruuid"].isNull())
        {
            useruuid_=std::make_shared<std::string>(pJson["useruuid"].asString());
        }
    }
    if(pJson.isMember("index"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["index"].isNull())
        {
            index_=std::make_shared<int16_t>((int16_t)pJson["index"].asInt64());
        }
    }
}

void UsergroupUser::updateByMasqueradedJson(const Json::Value &pJson,
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
            guuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            useruuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            index_=std::make_shared<int16_t>((int16_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
}

void UsergroupUser::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("guuid"))
    {
        dirtyFlag_[0] = true;
        if(!pJson["guuid"].isNull())
        {
            guuid_=std::make_shared<std::string>(pJson["guuid"].asString());
        }
    }
    if(pJson.isMember("useruuid"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["useruuid"].isNull())
        {
            useruuid_=std::make_shared<std::string>(pJson["useruuid"].asString());
        }
    }
    if(pJson.isMember("index"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["index"].isNull())
        {
            index_=std::make_shared<int16_t>((int16_t)pJson["index"].asInt64());
        }
    }
}

const std::string &UsergroupUser::getValueOfGuuid() const noexcept
{
    const static std::string defaultValue = std::string();
    if(guuid_)
        return *guuid_;
    return defaultValue;
}
const std::shared_ptr<std::string> &UsergroupUser::getGuuid() const noexcept
{
    return guuid_;
}
void UsergroupUser::setGuuid(const std::string &pGuuid) noexcept
{
    guuid_ = std::make_shared<std::string>(pGuuid);
    dirtyFlag_[0] = true;
}
void UsergroupUser::setGuuid(std::string &&pGuuid) noexcept
{
    guuid_ = std::make_shared<std::string>(std::move(pGuuid));
    dirtyFlag_[0] = true;
}

const std::string &UsergroupUser::getValueOfUseruuid() const noexcept
{
    const static std::string defaultValue = std::string();
    if(useruuid_)
        return *useruuid_;
    return defaultValue;
}
const std::shared_ptr<std::string> &UsergroupUser::getUseruuid() const noexcept
{
    return useruuid_;
}
void UsergroupUser::setUseruuid(const std::string &pUseruuid) noexcept
{
    useruuid_ = std::make_shared<std::string>(pUseruuid);
    dirtyFlag_[1] = true;
}
void UsergroupUser::setUseruuid(std::string &&pUseruuid) noexcept
{
    useruuid_ = std::make_shared<std::string>(std::move(pUseruuid));
    dirtyFlag_[1] = true;
}

const int16_t &UsergroupUser::getValueOfIndex() const noexcept
{
    const static int16_t defaultValue = int16_t();
    if(index_)
        return *index_;
    return defaultValue;
}
const std::shared_ptr<int16_t> &UsergroupUser::getIndex() const noexcept
{
    return index_;
}
void UsergroupUser::setIndex(const int16_t &pIndex) noexcept
{
    index_ = std::make_shared<int16_t>(pIndex);
    dirtyFlag_[2] = true;
}

void UsergroupUser::updateId(const uint64_t id)
{
}

const std::vector<std::string> &UsergroupUser::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "guuid",
        "useruuid",
        "index"
    };
    return inCols;
}

void UsergroupUser::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getGuuid())
        {
            binder << getValueOfGuuid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getUseruuid())
        {
            binder << getValueOfUseruuid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getIndex())
        {
            binder << getValueOfIndex();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> UsergroupUser::updateColumns() const
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

void UsergroupUser::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getGuuid())
        {
            binder << getValueOfGuuid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getUseruuid())
        {
            binder << getValueOfUseruuid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getIndex())
        {
            binder << getValueOfIndex();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value UsergroupUser::toJson() const
{
    Json::Value ret;
    if(getGuuid())
    {
        ret["guuid"]=getValueOfGuuid();
    }
    else
    {
        ret["guuid"]=Json::Value();
    }
    if(getUseruuid())
    {
        ret["useruuid"]=getValueOfUseruuid();
    }
    else
    {
        ret["useruuid"]=Json::Value();
    }
    if(getIndex())
    {
        ret["index"]=getValueOfIndex();
    }
    else
    {
        ret["index"]=Json::Value();
    }
    return ret;
}

Json::Value UsergroupUser::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 3)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getGuuid())
            {
                ret[pMasqueradingVector[0]]=getValueOfGuuid();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getUseruuid())
            {
                ret[pMasqueradingVector[1]]=getValueOfUseruuid();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getIndex())
            {
                ret[pMasqueradingVector[2]]=getValueOfIndex();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getGuuid())
    {
        ret["guuid"]=getValueOfGuuid();
    }
    else
    {
        ret["guuid"]=Json::Value();
    }
    if(getUseruuid())
    {
        ret["useruuid"]=getValueOfUseruuid();
    }
    else
    {
        ret["useruuid"]=Json::Value();
    }
    if(getIndex())
    {
        ret["index"]=getValueOfIndex();
    }
    else
    {
        ret["index"]=Json::Value();
    }
    return ret;
}

bool UsergroupUser::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("guuid"))
    {
        if(!validJsonOfField(0, "guuid", pJson["guuid"], err, true))
            return false;
    }
    else
    {
        err="The guuid column cannot be null";
        return false;
    }
    if(pJson.isMember("useruuid"))
    {
        if(!validJsonOfField(1, "useruuid", pJson["useruuid"], err, true))
            return false;
    }
    else
    {
        err="The useruuid column cannot be null";
        return false;
    }
    if(pJson.isMember("index"))
    {
        if(!validJsonOfField(2, "index", pJson["index"], err, true))
            return false;
    }
    else
    {
        err="The index column cannot be null";
        return false;
    }
    return true;
}
bool UsergroupUser::validateMasqueradedJsonForCreation(const Json::Value &pJson,
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
bool UsergroupUser::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("guuid"))
    {
        if(!validJsonOfField(0, "guuid", pJson["guuid"], err, false))
            return false;
    }
    if(pJson.isMember("useruuid"))
    {
        if(!validJsonOfField(1, "useruuid", pJson["useruuid"], err, false))
            return false;
    }
    if(pJson.isMember("index"))
    {
        if(!validJsonOfField(2, "index", pJson["index"], err, false))
            return false;
    }
    return true;
}
bool UsergroupUser::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
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
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool UsergroupUser::validJsonOfField(size_t index,
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

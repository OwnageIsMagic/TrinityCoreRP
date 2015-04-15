//########################## TrinityRP
#include "Player.h"

// DisplayID (morph)
void Player::_SaveDisplayId(SQLTransaction& trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_DISPLAYID);
    stmt->setUInt32(0, GetGUIDLow());
    stmt->setUInt32 (1 , GetDisplayId ());
    stmt->setUInt32(2, GetDisplayId ());
    trans->Append(stmt);
}

void Player::_LoadDisplayId(PreparedQueryResult result)
{
  m_monthlyquests.clear();

  if (result)
  {
          Field* fields = result->Fetch();
          uint32 displayid = fields[0].GetUInt32();
          SetDisplayId (displayid);
          TC_LOG_DEBUG("entities.player.loading", "Display ID {%u} for player (GUID: %u)", displayid, GetGUIDLow());
  }

  m_MonthlyQuestChanged = false;
}

//########################## TrinityRP

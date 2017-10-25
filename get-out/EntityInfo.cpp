#include "EntityInfo.h"


EntityInfo EntityInfo::createPlayerInfo(int id, EntityType type, int parentId, const std::string& name, const std::string& description, int maxItems, int startingRoomId)
{
	EntityInfo info{ id, type, parentId, name, description };
	info.player.maxItems = maxItems;
	info.player.startingRoomId = startingRoomId;
	return info;
}


EntityInfo EntityInfo::createRoomInfo(int id, EntityType type, int parentId, const std::string & name, const std::string & description, bool isDark)
{
	EntityInfo info{ id, type, parentId, name, description };
	info.room.isDark = isDark;
	return info;
}


EntityInfo EntityInfo::createExitInfo(int id, EntityType type, int parentId, const std::string & name, const std::string & description, Direction direction, bool isLocked, const char* lockedDescription, int targetRoomId)
{
	EntityInfo info{ id, type, parentId, name, description };
	info.exit.direction = direction;
	info.exit.isLocked = isLocked;
	info.exit.lockedDescription = lockedDescription;
	info.exit.targetRoomId = targetRoomId;
	return info;
}

EntityInfo EntityInfo::createItemInfo(int id, EntityType type, int parentId, const std::string & name, const std::string & description, const char * inspectDescription, bool isVisibleInDark, bool hasLight)
{
	EntityInfo info{ id, type, parentId, name, description };
	info.item.inspectDescription = inspectDescription;
	info.item.isVisibleInDark = isVisibleInDark;
	info.item.hasLight = hasLight;
	return info;
}

EntityInfo EntityInfo::createInteractableInfo(int id, EntityType type, int parentId, const std::string & name, const std::string & description, const char * inspectDescription, bool isVisibleInDark)
{
	EntityInfo info{ id, type, parentId, name, description };
	info.interactable.inspectDescription = inspectDescription;
	info.interactable.isVisibleInDark = isVisibleInDark;
	return info;
}

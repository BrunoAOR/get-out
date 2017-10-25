#ifndef H_ACTION_FACTORY
#define H_ACTION_FACTORY

#include <vector>
#include <string>
class Action;
class EntityFactory;
class ActionEffect;
enum class ActionType;



class ActionFactory
{
public:
	ActionFactory(EntityFactory* entityFactory);
	~ActionFactory();
	ActionFactory(const ActionFactory& source) = delete;
	ActionFactory& operator=(const ActionFactory& source) = delete;

	void close();

	Action* createAction(ActionType type, const std::string& description, std::vector<ActionEffect*> effects, bool shouldDestroy, int firstEntityId, int secondEntityId = -1);

	Action* getAction(ActionType actionType, const std::string& firstEntityName, const std::string& secondEntityName = "");
	void removeAction(Action* action);

private:
	std::vector<Action*> m_actions;
	EntityFactory* m_entityFactory;
};


#endif // !H_ACTION_FACTORY

#ifndef SCENE_STATE_MACHINE_HPP
#define SCENE_STATE_MACHINE_HPP
#include <unordered_map>
#include <memory>
#include "Scene.hpp"

class SceneStateMachine {
public:
	SceneStateMachine();
	~SceneStateMachine();

	void EventHandler();
	void Update();
	void Draw();
public:
	void Add(std::shared_ptr<Scene> pScene);
	void Remove(unsigned int id);
	void TransitionTo(unsigned int id);
private:
	std::unordered_map<unsigned int, std::shared_ptr<Scene>> Scenes_;
	std::shared_ptr<Scene> currentScene_;
	unsigned int totalSceneID_;
};

#endif // !SCENE_STATE_MACHINE_HPP

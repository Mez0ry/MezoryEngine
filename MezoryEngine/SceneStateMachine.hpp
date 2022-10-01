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
/**
* @brief Adds scene to the scene array
*/
	void Add(std::shared_ptr<Scene> pScene);
/**
* @brief Removes scene from the scene array
*/
	void Remove(unsigned int id);
/**
* @brief Sets the scene
*/
	void TransitionTo(unsigned int id);
private:
	std::unordered_map<unsigned int, std::shared_ptr<Scene>> Scenes_;
	std::shared_ptr<Scene> currentScene_;
	unsigned int totalScenes;
};

#endif // !SCENE_STATE_MACHINE_HPP

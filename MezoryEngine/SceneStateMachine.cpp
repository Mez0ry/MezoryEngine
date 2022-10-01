#include "SceneStateMachine.hpp"

SceneStateMachine::SceneStateMachine() : totalSceneID_(0)
{

}

SceneStateMachine::~SceneStateMachine()
{
}

void SceneStateMachine::EventHandler()
{
	currentScene_.get()->EventHandler();
}

void SceneStateMachine::Update()
{
	currentScene_.get()->Update();
}

void SceneStateMachine::Draw()
{
	currentScene_.get()->Draw();
}

void SceneStateMachine::Add(std::shared_ptr<Scene> pScene)
{
	Scenes_.insert(std::make_pair(totalSceneID_, pScene));
	totalSceneID_++;
}

void SceneStateMachine::Remove(unsigned int id)
{
	Scenes_.erase(id);
	totalSceneID_--;
}

void SceneStateMachine::TransitionTo(unsigned int id)
{
	std::unordered_map<unsigned int, std::shared_ptr<Scene>>::iterator it = Scenes_.find(id);
	if (it != Scenes_.end()) {
		if (currentScene_) {
			currentScene_.reset();
		}
		currentScene_ = it->second;
	}
}

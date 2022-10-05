#include "SceneStateMachine.hpp"

SceneStateMachine::SceneStateMachine() : totalScenes(0)
{

}

SceneStateMachine::~SceneStateMachine()
{
}

void SceneStateMachine::EventHandler()
{
	if (!currentScene_) 
		return;

	currentScene_->EventHandler();
}

void SceneStateMachine::Update()
{
	if (!currentScene_)
		return;
	currentScene_->Update();
}

void SceneStateMachine::Draw()
{
	if (!currentScene_)
		return;
	currentScene_->Draw();
}

void SceneStateMachine::Add(std::shared_ptr<Scene> pScene)
{
	Scenes_.insert(std::make_pair(totalScenes, pScene));
	totalScenes++;
}

void SceneStateMachine::Remove(unsigned int id)
{
	Scenes_.erase(id);
	totalScenes--;
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

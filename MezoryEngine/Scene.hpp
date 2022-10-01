#ifndef SCENE_HPP
#define SCENE_HPP
/**
* @brief Scene interface
*/
class Scene {
public:
	virtual ~Scene(){}
	virtual void EventHandler() {}
	virtual void Update() {}
	virtual void Draw() {}
private:
};

#endif // !SCENE_HPP

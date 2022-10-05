#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "Component.hpp"
#include <unordered_map>
#include <memory>

namespace ECS {

	class Entity {
	private:
		using UnorderedMapType = std::unordered_map<unsigned int, std::unique_ptr<Component>>;
	public:
		Entity();
		~Entity() noexcept;

		template <typename _TComponent>
		void AddComponent();

		template <typename _TComponent>
		_TComponent* get_component();

	private:
		UnorderedMapType components_;
	};

} // !namespace ECS
#endif // !ENTITY_HPP

ECS::Entity::Entity()
{
	
}

ECS::Entity::~Entity() noexcept
{
	
}

template<typename _TComponent>
inline void ECS::Entity::AddComponent()
{
	static_assert(std::is_base_of<Component, _TComponent>::value == true, "The component you want to add is not a derived object of the 'Component' base class");
	std::unique_ptr<_TComponent> ptr(std::make_unique<_TComponent>());
	components_.insert(std::make_pair(ptr->get_id(), std::move(ptr)));
}

template<typename _TComponent>
inline _TComponent* ECS::Entity::get_component()
{
	static_assert(std::is_base_of<Component, _TComponent>::value == true, "The component you want to get is not a derived object of the 'Component' base class");

	UnorderedMapType::iterator it = components_.find(_TComponent().get_id());

	if (it != components_.end()) {
		return static_cast<_TComponent*>(it->second.get());
	}

	return nullptr;
}

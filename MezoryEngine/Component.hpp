#ifndef COMPONENT_HPP
#define COMPONENT_HPP

namespace ECS {

	template <typename _Ty>
	class ComponentUniqueID {
	public:
		ComponentUniqueID() = default;
		size_t get_id() const { return id_; }
	private:
		const static size_t id_;
	};

	static size_t inc_id;
	template<typename T>
	const size_t ComponentUniqueID<T>::id_(inc_id++);

	class Component {
	public:
		Component() = default;
		virtual ~Component() {}
	};

}// !namespace ECS
#endif // !COMPONENT_HPP

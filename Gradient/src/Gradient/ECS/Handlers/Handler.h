#pragma once

namespace
{
	enum class HandlerType
	{
		Camera,
		Model,
		Physics
	};

	class Handler
	{
	protected:
		HandlerType type;

	public:
		Handler(HandlerType t)
			: type(t)
		{ }
		~Handler() = default;

		virtual void OnInit();

		virtual void OnUpdate();
	};
}

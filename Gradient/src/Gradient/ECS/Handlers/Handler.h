#pragma once

namespace
{
	enum class HandlerType
	{
		OrthographicCamera,
		PerspectiveCamera,
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

		virtual void OnInit() = 0;

		virtual void OnUpdate() = 0;
	};
}

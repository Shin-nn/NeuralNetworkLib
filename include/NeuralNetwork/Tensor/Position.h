#pragma once

#include <SimpleJSON/SerializableObject.h>

#include <cstdlib>
#include <array>

namespace NeuralNetwork {
	namespace Tensor {

		template <std::size_t DIMS = 3>
		class Position : public SimpleJSON::SerializableObject {
			public:

			protected:
			private:
				std::array<std::size_t,DIMS> _position;
		};
	}
}
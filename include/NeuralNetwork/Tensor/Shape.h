#pragma once

#include <SimpleJSON/SerializableObject.h>

#include <cstdlib>
#include <array>

namespace NeuralNetwork {
	namespace Tensor {

		template <std::size_t DIMS = 3>
		class Shape : public SimpleJSON::SerializableObject {
			public:
				Shape() {
					_shape.fill(0);
				}

				std::size_t dimensions() const {
					return _shape.size();
				}

				std::size_t& operator[](std::size_t dim) {
					return _shape[dim];
				}

				std::size_t operator[](std::size_t dim) const {
					return _shape[dim];
				}

			protected:

			private:
				std::array<std::size_t,DIMS> _shape;
		};
	}
}
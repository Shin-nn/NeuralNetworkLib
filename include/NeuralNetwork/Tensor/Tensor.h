#pragma once

#include "Shape.h"
#include "Position.h"

#include <SimpleJSON/SerializableObject.h>

#include <cstdlib>
#include <array>

namespace NeuralNetwork {
	namespace Tensor {

		template <typename T, std::size_t DIMS = 3>
		class Tensor : public SimpleJSON::SerializableObject {
			public:
				const Shape& getShape() const {
					return _shape;
				}

				Shape& getShape() {
					return _shape;
				}
			private:
				Shape<DIMS> _shape;
		};
	}
}
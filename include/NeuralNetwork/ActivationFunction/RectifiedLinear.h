/*
 *  Copyright 2016 Tomas Cernik, Tom.Cernik@gmail.com
 *  All rights reserved.
 *
 *  This file is part of NeuralNetworkLib
 *
 *  NeuralNetworkLib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  NeuralNetworkLib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with NeuralNetworkLib.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "./ActivationFunction.h"

#include <cassert>

namespace NeuralNetwork {
namespace ActivationFunction {

	class RectifiedLinear: public ActivationFunction {
		public:
			RectifiedLinear(const float &lambdaP=0.1): lambda(lambdaP) {}

			inline virtual float derivatedOutput(const float &inp,const float &) const override {
				return inp > 0.0f ? lambda : 0.0f;
			}

			inline virtual float operator()(const float &x) const override {
				return std::max(0.0f,x);
			};

			virtual std::unique_ptr<ActivationFunction> clone() const override {
				return std::make_unique<RectifiedLinear>(lambda);
			}

			virtual SimpleJSON::Type::Object serialize() const override {
				return {{"class", "NeuralNetwork::ActivationFunction::RectifiedLinear"}, {"lambda", lambda}};
			}

			static std::unique_ptr<RectifiedLinear> deserialize(const SimpleJSON::Type::Object &obj) {
				return std::unique_ptr<RectifiedLinear>(new RectifiedLinear(obj["lambda"].as<double>()));
			}

		protected:
			float lambda;
			NEURAL_NETWORK_REGISTER_ACTIVATION_FUNCTION(NeuralNetwork::ActivationFunction::RectifiedLinear, RectifiedLinear::deserialize)
	};
}
}
/* file: prelu_layer_forward_types.h */
/*******************************************************************************
* Copyright 2014-2017 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of the parametric rectifier linear unit (prelu) layer
//--
*/

#ifndef __PRELU_LAYER_FORWARD_TYPES_H__
#define __PRELU_LAYER_FORWARD_TYPES_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "data_management/data/homogen_tensor.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/layer_forward_types.h"
#include "algorithms/neural_networks/layers/prelu/prelu_layer_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
/**
 * \brief Contains classes the prelu layer
 */
namespace prelu
{
/**
 * @defgroup prelu_forward Forward Parametric Rectifier Linear Unit (pReLU) Layer
 * \copydoc daal::algorithms::neural_networks::layers::prelu::forward
 * @ingroup prelu
 * @{
 */
/**
* \brief Contains classes for the forward prelu layer
*/
namespace forward
{
/**
* \brief Contains version 1.0 of Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
*/
namespace interface1
{
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__PRELU__FORWARD__INPUT"></a>
 * \brief %Input objects for the forward prelu layer
 */
class DAAL_EXPORT Input : public layers::forward::Input
{
public:
    typedef layers::forward::Input super;
    /** \brief Default constructor */
    Input();

    /** Copy constructor */
    Input(const Input& other);

    /**
    * Gets the input of the forward prelu layer
    */
    using layers::forward::Input::get;

    /**
    * Sets the input of the forward prelu layer
    */
    using layers::forward::Input::set;

    virtual ~Input() {}

    /**
     * Allocates memory to store weights for the forward prelu layer
     * \param[in] par      %Parameter of the algorithm
     * \param[in] method   Computation method for the algorithm
     *
     * \return Status of computations
     */
    template <typename algorithmFPType>
    DAAL_EXPORT services::Status allocate(const daal::algorithms::Parameter *par, const int method);

    /**
    * Returns dimensions of weights tensor
    * \return Dimensions of weights tensor
    */
    virtual const services::Collection<size_t> getWeightsSizes(const layers::Parameter *par) const DAAL_C11_OVERRIDE;

    /**
     * Returns dimensions of biases tensor
     * \return Dimensions of biases tensor
     */
    virtual const services::Collection<size_t> getBiasesSizes(const layers::Parameter *parameter) const DAAL_C11_OVERRIDE;

    /**
     * Checks input object of the forward prelu layer
     * \param[in] par     Layer parameter
     * \param[in] method  Computation method of the layer
     *
     * \return Status of computations
     */
    services::Status check(const daal::algorithms::Parameter *par, int method) const DAAL_C11_OVERRIDE;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__PRELU__FORWARD__RESULT"></a>
 * \brief Provides methods to access the result obtained with the compute() method of the forward prelu layer
 */
class DAAL_EXPORT Result : public layers::forward::Result
{
public:
    DECLARE_SERIALIZABLE();
    /** \brief Default constructor */
    Result();
    virtual ~Result() {};

    /**
     * Returns the result of the forward prelu layer
     */
    using layers::forward::Result::get;

    /**
    * Sets the result of the forward prelu layer
    */
    using layers::forward::Result::set;

    /**
     * Returns the result of the forward prelu layer
     * \param[in] id    Identifier of the result
     * \return          Result that corresponds to the given identifier
     */
    services::SharedPtr<data_management::Tensor> get(LayerDataId id) const;

    /**
     * Sets the result of the forward prelu layers
     * \param[in] id      Identifier of the result
     * \param[in] value   Result
     */
    void set(LayerDataId id, const services::SharedPtr<data_management::Tensor> &value);

    /**
     * Checks the result of the forward prelu layer
     * \param[in] input   %Input object for the algorithm
     * \param[in] par     %Parameter of the algorithm
     * \param[in] method  Computation method
     *
     * \return Status of computations
     */
    services::Status check(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, int method) const DAAL_C11_OVERRIDE;

    /**
     * Returns dimensions of value tensor
     * \return Dimensions of value tensor
     */
    virtual const services::Collection<size_t> getValueSize(const services::Collection<size_t> &inputSize,
                                                            const daal::algorithms::Parameter *par, const int method) const DAAL_C11_OVERRIDE;

    /**
     * Allocates memory to store the result of the forward prelu layer
     * \param[in] input    Pointer to an object containing the input data
     * \param[in] par      %Parameter of the algorithm
     * \param[in] method   Computation method for the algorithm
     *
     * \return Status of computations
     */
    template <typename algorithmFPType>
    DAAL_EXPORT services::Status allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, const int method);

    /**
     * Sets the result that is used in backward prelu layer
     * \param[in] input     Pointer to an object containing the input data
     *
     * \return Status of computations
     */
    virtual services::Status setResultForBackward(const daal::algorithms::Input *input) DAAL_C11_OVERRIDE;

protected:
    /** \private */
    template<typename Archive, bool onDeserialize>
    void serialImpl(Archive *arch)
    {
        daal::algorithms::Result::serialImpl<Archive, onDeserialize>(arch);
    }

    void serializeImpl(data_management::InputDataArchive   *arch) DAAL_C11_OVERRIDE
    {serialImpl<data_management::InputDataArchive, false>(arch);}

    void deserializeImpl(data_management::OutputDataArchive *arch) DAAL_C11_OVERRIDE
    {serialImpl<data_management::OutputDataArchive, true>(arch);}
};
} // namespace interface1
using interface1::Input;
using interface1::Result;
} // namespace forward
/** @} */
} // namespace prelu
} // namespace layers
} // namespace neural_networks
} // namespace algorithm
} // namespace daal
#endif

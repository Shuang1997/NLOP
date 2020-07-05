#ifndef ADADELTAPARAMS_HPP
#define ADADELTAPARAMS_HPP

#include <OptimizerParams/LineSearchParams.hpp>

namespace NLOP {
/// @class NLOP::AdaDeltaParams
/// @brief Params of AdaDelta optimization methods
class AdaDeltaParams: public LineSearchParams
{
public:
    /// @brief Constructor
    AdaDeltaParams() { setDefaults(); }

    /// @brief Set and get mininum gradient to control iterations to stop
    void setMinGradient(const double value) { min_gradient = value; }
    double getMinGradient() const { return min_gradient; }

    /// @brief Use default optimizer params
    void setDefaults() override
    {
        min_gradient = 0.01;
        alpha = 0.01;
        gamma = 0.9;
        epsilon = 1e-8;

        max_iteration_times = 10000;
        iteration_times = 0;
        verbosity = SUMMARY;
    }

    /// @brief print params of optimizer
    void print(const std::string &str) override
    {
        std::cout << str << "\n";
        std::cout << "*********************************************" << "\n";
        std::cout << "maximum iterations: " << max_iteration_times << "\n";
        std::cout << "verbosity: " << verbosityTranslator(verbosity) << "\n";
        std::cout << "gradient thresthold: " << min_gradient << "\n";
        std::cout << "Learning rate: " << alpha << "\n";
        std::cout << "Decay rate: " << gamma << "\n";
        std::cout << "*********************************************" << std::endl;
    }

    /// @brief Setters and Getters of Params
    void setAlpha (const double value) { alpha = value; }
    void setGamma (const double value) { gamma = value; }
    void setEpsilon (const double value) { epsilon = value; }

    double getAlpha() const { return alpha; }
    double getGamma() const { return gamma; }
    double getEpsilon() const { return epsilon; }

private:
    double min_gradient; // Gradient threshold to stop the iterations
    double alpha;        // Learning rate
    double gamma;        // Decay rate
    double epsilon;      // Prevent division by 0
};
}


#endif

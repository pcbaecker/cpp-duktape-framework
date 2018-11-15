#pragma once

#include <string>
#include <duktape.h>

namespace js {

    class Context {
    public:
        /**
         * @brief Constructor.
         *
         * @throws std::exception
         */
        Context();

        /**
         * @brief Destructor.
         */
        ~Context();

        /**
         * @brief Returns the context that is hold by this class.
         *
         * @return Pointer to the context.
         */
        duk_context* getContext() noexcept;

        /**
         * @brief Evaluates the given js code but doesnt expects a result.
         *
         * @param code The code to evaluate.
         */
        void evalNoResult(const std::string& code);

        void registerFunction(duk_c_function function);

    private:
        /**
         * @brief The context that is used for all operations.
         */
        duk_context* pContext = nullptr;
    };

}
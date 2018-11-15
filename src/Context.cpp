#include <exception>
#include "../include/js/Context.hpp"

namespace js {

    Context::Context() {
        // Try to create the context
        this->pContext = duk_create_heap_default();
        if (this->pContext == nullptr) {
            throw std::exception();
        }
    }

    Context::~Context() {
        if (this->pContext != nullptr) {
            duk_destroy_heap(this->pContext);
            this->pContext = nullptr;
        }
    }

    duk_context *Context::getContext() noexcept {
        return this->pContext;
    }

    void Context::evalNoResult(const std::string &code) {
        auto result = duk_peval_string_noresult(this->pContext, code.c_str());
        if (result != 0) {
            throw std::exception();
        }
    }

    void Context::registerFunction(duk_c_function function) {

    }
}

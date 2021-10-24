#include "DistrhoPlugin.hpp"

START_NAMESPACE_DISTRHO

class HalfInverter : public Plugin
{
public:
    HalfInverter() : Plugin(0, 0, 0)
    {
    }

    ~HalfInverter() override
    {
    }

protected:
    const char* getLabel() const override
    {
        return "HalfInverter";
    }

    const char* getDescription() const override
    {
        return "Invert halfway";
    }

    const char* getMaker() const override
    {
        return "vanheusden.com";
    }

    const char* getHomePage() const override
    {
        return "https://vanheusden.com/disthro/halfinverter";
    }

    const char* getLicense() const override
    {
        return "Apache License v2.0";
    }

    uint32_t getVersion() const override
    {
        return d_version(1, 0, 0);
    }

    int64_t getUniqueId() const override
    {
        return d_cconst('F', 'v', 'H', '2');
    }

    void initParameter(uint32_t index, Parameter& parameter) override
    {
    }

    float getParameterValue(uint32_t index) const override
    {
	    return 0.0f;
    }

    void setParameterValue(uint32_t index, float value) override
    {
    }

    void run(const float** inputs, float** outputs, uint32_t frames) override
    {
        const float *const in = inputs[0];
        float *const out = outputs[0];

	for(uint32_t i=0; i<frames; i++) {
		if (in[i] >= 0)
			out[i] = 1.0 - in[i];
		else
			out[i] = -(1.0 - fabs(in[i]));
	}
    }

private:
    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HalfInverter)
};


Plugin* createPlugin()
{
    return new HalfInverter();
}

END_NAMESPACE_DISTRHO

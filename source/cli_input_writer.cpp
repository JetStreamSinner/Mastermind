#include "cli_input_writer.h"
#include <ostream>

class CliInputWriter::CliInputWriterImpl {
public:
    explicit CliInputWriterImpl(std::shared_ptr<std::ostream> out);
    void writeMessage(const std::string &message);
private:
    std::shared_ptr<std::ostream> _outstr;
};

CliInputWriter::CliInputWriterImpl::CliInputWriterImpl(std::shared_ptr<std::ostream> out) : _outstr(std::move(out)) {

}

void CliInputWriter::CliInputWriterImpl::writeMessage(const std::string &message) {
    _outstr->write(message.c_str(), message.size());
    _outstr->put('\n');
}

CliInputWriter::CliInputWriter(std::shared_ptr<std::ostream> out) : _impl(std::make_unique<CliInputWriter::CliInputWriterImpl>(out)) {

}

void CliInputWriter::writeMessage(const std::string &message) {
    _impl->writeMessage(message);
}

CliInputWriter::~CliInputWriter() = default;

require 'sigcdump/version'
require 'sigcdump/sigcdump'

class << Sigcdump
  def setup(signal = ENV['SIGCDUMP_SIGNAL'] || 'SIGCONT', path = ENV['SIGCDUMP_PATH'])
    Kernel.trap(signal) do
      begin
        dump(path)
      rescue
      end
    end
  end

  def dump(arg = ENV['SIGCDUMP_PATH'])
    with_path_and_io(arg) do |path, io|
      io.write "Sigcdump at #{Time.now} process #{Process.pid} (#{$0})\n"
      io.flush
      dump_internal(path)
    end
  end

  private def with_path_and_io(path, &block)
    case path
    when IO
      raise NotImplementedError, 'specifying IO in Sigcdump.dump is not implemented yet'
    when '-'
      block.call(path, STDOUT)
    when '+'
      block.call(path, STDERR)
    else
      if path == nil || path == ''
        path = "/tmp/sigcdump-#{Process.pid}.log"
      end
      File.open(path, 'a') do |io|
        block.call(path, io)
      end
    end
  end

  private :dump_internal
end

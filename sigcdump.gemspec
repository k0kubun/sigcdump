lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'sigcdump/version'

Gem::Specification.new do |spec|
  spec.name          = 'sigcdump'
  spec.version       = Sigcdump::VERSION
  spec.authors       = ['Takashi Kokubun']
  spec.email         = ['takashikkbn@gmail.com']

  spec.summary       = %q{Sigdump for C backtrace}
  spec.description   = %q{Sigdump for C backtrace}
  spec.homepage      = 'https://github.com/k0kubun/sigcdump'
  spec.license       = 'MIT'

  spec.files         = Dir.chdir(File.expand_path('..', __FILE__)) do
    `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  end + %w[
    ext/sigcdump/ruby/addr2line.c
  ]
  spec.bindir        = 'exe'
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.require_paths = ['lib']
  spec.extensions    = ['ext/sigcdump/extconf.rb']

  spec.add_development_dependency 'bundler'
  spec.add_development_dependency 'rake'
  spec.add_development_dependency 'rake-compiler'
end

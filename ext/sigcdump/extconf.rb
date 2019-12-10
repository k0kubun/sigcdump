require 'mkmf'

ruby_dir = File.expand_path('./ruby', __dir__)
$INCFLAGS << " -I#{ruby_dir}"

$srcs = %w[
  sigcdump.c
]
%w[
  addr2line.c
].each do |c|
  FileUtils.ln_s(File.join(ruby_dir, c), c, force: true)
  $srcs << c
end

create_makefile('sigcdump/sigcdump')

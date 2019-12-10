require "bundler/gem_tasks"
require "rake/extensiontask"

task :build => :compile

Rake::ExtensionTask.new("sigcdump") do |ext|
  ext.lib_dir = "lib/sigcdump"
end

task :default => [:clobber, :compile, :spec]

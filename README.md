# Sigcdump

[Sigdump](https://github.com/frsyuki/sigdump) for C backtrace.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'sigcdump'
```

And then execute:

    $ bundle

NOTE: Unlike sigdump, this gem supports only CRuby.

## Usage

```rb
require 'sigcdump'
Sigcdump.setup('SIGCONT')
```

or:

```rb
# this calls Sigcdump.setup('SIGCONT')
require 'sigcdump/setup'
```

Then `kill -CONT <pid>` will show a C backtrace of a CRuby process to `/tmp/sigcdump-#{Process.pid}.log`.

### stdout / stderr

`Sigcdump.dump('-')` dumps output to stdout, and `Sigcdump.dump('+')` dumps output to stderr.

```
irb(main)[01:0]> require 'sigcdump'
=> true
irb(main)[02:0]> Sigcdump.dump('-')
Sigcdump at 2019-12-10 00:48:56 -0800 process 61249 (irb)
/Users/k0kubun/.rbenv/versions/ruby/lib/ruby/gems/2.7.0/gems/sigcdump-0.1.0/lib/sigcdump/sigcdump.bundle(rb_sigcdump_dump_internal+0xe7) [0x10b129aa7]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_call_cfunc+0x182) [0x10768c3f2]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_exec_core+0x3e2e) [0x10767287e]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_vm_exec+0xa79) [0x107687819]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_f_eval+0x304) [0x107681384]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_call_cfunc+0x182) [0x10768c3f2]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_exec_core+0x3e2e) [0x10767287e]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_vm_exec+0xa79) [0x107687819]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(loop_i+0x29) [0x107697159]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_vrescue2+0x114) [0x1074d4f24]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_rescue2+0x7b) [0x1074d4deb]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_call_cfunc+0x182) [0x10768c3f2]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_exec_core+0x3cf5) [0x107672745]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_vm_exec+0xa79) [0x107687819]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(catch_i+0x67) [0x1076970d7]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_catch_protect+0xd5) [0x107682ac5]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_f_catch+0x57) [0x1076831a7]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_call_cfunc+0x182) [0x10768c3f2]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_exec_core+0x3cf5) [0x107672745]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_vm_exec+0xa79) [0x107687819]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(catch_i+0x67) [0x1076970d7]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_catch_protect+0xd5) [0x107682ac5]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_f_catch+0x57) [0x1076831a7]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_call_cfunc+0x182) [0x10768c3f2]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_exec_core+0x3cf5) [0x107672745]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_vm_exec+0xa79) [0x107687819]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(load_iseq_eval+0xb9) [0x10752ead9]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_f_load+0x114) [0x10752e014]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_call_cfunc+0x182) [0x10768c3f2]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(vm_exec_core+0x3e2e) [0x10767287e]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_vm_exec+0xa79) [0x107687819]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(rb_ec_exec_node+0xc6) [0x1074d4516]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(ruby_run_node+0x55) [0x1074d43f5]
/Users/k0kubun/.rbenv/versions/ruby/bin/ruby(main+0x71) [0x107429bf1]

=> true
```

## License

The gem is available as open source under the terms of the [Ruby License](./LICENSE.txt).

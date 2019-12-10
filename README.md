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
Sigcdump.setup('SIGTTIN')
```

or:

```rb
# this calls Sigcdump.setup('SIGTTIN')
require 'sigcdump/setup'
```

Then `kill -TTIN <pid>` will show a C backtrace of a CRuby process.

## License

The gem is available as open source under the terms of the [Ruby License](./LICENSE.txt).

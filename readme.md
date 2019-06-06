# SAM4SPrintIO

This repository contains the [iOS SDK v1.0.0 for SAM4S Receipt Printer][SDK], packaged for usage with Carthage.

## Installation

Add the following line to your Cartfile:

```text
github "LinusU/SAM4SPrintIO" ~> 1.0.0
```

## Documentation

Read the [SAM4S iOS SDK Programmers Manual][Manual].

## Limitations

Because the upstream SDK is distributed as a pre-compiled binary, these limitations can only be fixed upstream:

- Only the `armv7` and `arm64` architectures are supported.
- Bitcode is not supported.

To work around these issues you need to disable bitcode in your entire project, and guard any access to the library behind compiler arch-checks.

```swift
#if arch(arm) || arch(arm64)
import SAM4SPrintIO
#endif

func findPrinters() -> [String] {
  #if arch(arm) || arch(arm64)
  let wiredManager = ConnectionManager.sharedWiredConnectionManager() as! ConnectionManager
  return wiredManager.connectedPrintersIPAddress() as! [String]
  #else
  return []
  #endif
}
```

## Hacking

The Xcode project is generated automatically from `project.yml` using [XcodeGen](https://github.com/yonaskolb/XcodeGen). It's only checked in because Carthage needs it, do not edit it manually.

```sh
$ mint run yonaskolb/xcodegen
💾  Saved project to SAM4SPrintIO.xcodeproj
```

[SDK]: http://sam4s.com/_common/ac_downFile.asp?f_url=/files/DOWN/20180110141355_1.zip&f_name=SAM4S_iOS_SDK_Sample_V1.0.0.zip
[Manual]: http://sam4s.com/_common/ac_downFile.asp?f_url=/files/DOWN/20180110141355_2.pdf&f_name=SAM4S%20iOS%20SDK%20Programmers%20Manual.pdf

cmake_minimum_required(VERSION 3.16)
project(qSIP VERSION 1.0 LANGUAGES C CXX)

# 빌드 설정
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Windows 특정 설정
if (WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-DSTATIC)
    add_definitions(-DHAVE_STRING_H -DWIN32 -DNDEBUG -D_WINDOWS)
    add_definitions(-UDEBUG)
endif ()

# Qt 경로 및 패키지 찾기
if (WIN32)
    # Windows에서 Qt 경로 설정 - 사용자 환경에 맞게 조정 필요
    set(QT_DIR "C:/Qt/6.5.0/msvc2019_64" CACHE PATH "Qt 설치 디렉토리")
    list(APPEND CMAKE_PREFIX_PATH "${QT_DIR}")
endif ()

# Qt 패키지 찾기
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)

# 출력 디렉토리 설정
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# re 라이브러리 (librealtime)
add_library(re STATIC
        re/src/base64/b64.c
        re/src/bfcp/attr.c
        re/src/bfcp/msg.c
        re/src/conf/conf.c
        re/src/crc32/crc32.c
        re/src/dbg/dbg.c
        re/src/dns/client.c
        re/src/dns/cstr.c
        re/src/dns/dname.c
        re/src/dns/rrlist.c
        re/src/dns/ns.c
        re/src/dns/rr.c
        re/src/dns/dns_hdr.c
        re/src/fmt/time.c
        re/src/fmt/ch.c
        re/src/fmt/hexdump.c
        re/src/fmt/pl.c
        re/src/fmt/print.c
        re/src/fmt/prm.c
        re/src/fmt/regex.c
        re/src/fmt/str.c
        re/src/hash/hash.c
        re/src/hash/func.c
        re/src/hmac/hmac_sha1.c
        re/src/httpauth/digest.c
        re/src/httpauth/basic.c
        re/src/ice/util.c
        re/src/ice/cand.c
        re/src/ice/candpair.c
        re/src/ice/chklist.c
        re/src/ice/comp.c
        re/src/ice/connchk.c
        re/src/ice/gather.c
        re/src/ice/ice.c
        re/src/ice/icem.c
        re/src/ice/icesdp.c
        re/src/ice/icestr.c
        re/src/ice/stunsrv.c
        re/src/jbuf/jbuf.c
        re/src/list/list.c
        re/src/main/method.c
        re/src/main/init.c
        re/src/main/main.c
        re/src/mbuf/mbuf.c
        re/src/md5/wrap.c
        re/src/md5/md5.c
        re/src/mem/mem.c
        re/src/natbd/natstr.c
        re/src/natbd/filtering.c
        re/src/natbd/genalg.c
        re/src/natbd/hairpinning.c
        re/src/natbd/lifetime.c
        re/src/natbd/mapping.c
        re/src/net/sockopt.c
        re/src/net/if.c
        re/src/net/net.c
        re/src/net/netstr.c
        re/src/net/rt.c
        re/src/rtp/source.c
        re/src/rtp/fb.c
        re/src/rtp/member.c
        re/src/rtp/ntp.c
        re/src/rtp/pkt.c
        re/src/rtp/rtcp.c
        re/src/rtp/rtp.c
        re/src/rtp/rtp_rr.c
        re/src/rtp/sdes.c
        re/src/rtp/sess.c
        re/src/sa/sa.c
        re/src/sa/ntop.c
        re/src/sa/pton.c
        re/src/sdp/session.c
        re/src/sdp/format.c
        re/src/sdp/media.c
        re/src/sdp/sdp_attr.c
        re/src/sdp/sdp_msg.c
        re/src/sdp/sdp_str.c
        re/src/sha/sha1.c
        re/src/sip/via.c
        re/src/sip/addr.c
        re/src/sip/auth.c
        re/src/sip/cseq.c
        re/src/sip/ctrans.c
        re/src/sip/dialog.c
        re/src/sip/keepalive.c
        re/src/sip/keepalive_udp.c
        re/src/sip/param.c
        re/src/sip/reply.c
        re/src/sip/request.c
        re/src/sip/sip.c
        re/src/sip/sip_msg.c
        re/src/sip/sip_transp.c
        re/src/sip/strans.c
        re/src/sipreg/reg.c
        re/src/sipsess/sipsess_request.c
        re/src/sipsess/accept.c
        re/src/sipsess/ack.c
        re/src/sipsess/close.c
        re/src/sipsess/connect.c
        re/src/sipsess/info.c
        re/src/sipsess/listen.c
        re/src/sipsess/modify.c
        re/src/sipsess/sip_sess.c
        re/src/sipsess/sipsess_reply.c
        re/src/stun/stun.c
        re/src/stun/stun_addr.c
        re/src/stun/stun_attr.c
        re/src/stun/stun_hdr.c
        re/src/stun/stun_ind.c
        re/src/stun/stun_msg.c
        re/src/stun/stun_rep.c
        re/src/stun/stun_req.c
        re/src/sys/sys.c
        re/src/sys/daemon.c
        re/src/sys/endian.c
        re/src/sys/rand.c
        re/src/tcp/tcp_high.c
        re/src/tcp/tcp.c
        re/src/telev/telev.c
        re/src/tmr/tmr.c
        re/src/udp/udp.c
        re/src/uri/uric.c
        re/src/uri/ucmp.c
        re/src/uri/uri.c
        re/src/mod/mod.c
        re/src/net/net_sock.c
        re/src/sys/sleep.c
        re/src/sipevent/subscribe.c
        re/src/sipevent/notify.c
        re/src/sipevent/sipevent_listen.c
        re/src/sipevent/sipevent_msg.c
        re/src/bfcp/conn.c
        re/src/bfcp/bfcp_request.c
        re/src/bfcp/bfcp_reply.c
        re/src/fmt/str_error.c
        re/src/sa/printaddr.c
        re/src/stun/stunstr.c
        re/src/stun/stun_keepalive.c
        re/src/stun/stun_ctrans.c
        re/src/stun/dnsdisc.c
        re/src/sip/sip_call_info.c
        re/src/sip/sip_alert_info.c
        re/src/sys/sys_time.c
        re/src/sip/sip_access_url.c
)

target_include_directories(re PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/re/include
)

if (WIN32)
    target_sources(re PRIVATE
            re/src/net/win32/ifaddrs.c
            re/src/mod/win32/dll.c
            re/src/dns/win32/srv.c
    )
    target_link_libraries(re PUBLIC ws2_32 iphlpapi)
endif ()

# rem 라이브러리 (리얼타임 미디어)
add_library(rem STATIC
        rem/src/aubuf/aubuf.c
        rem/src/auresamp/resamp.c
        rem/src/autone/tone.c
        rem/src/fir/fir.c
        rem/src/g711/g711.c
        rem/src/aufile/wave.c
        rem/src/aufile/aufile.c
)

target_include_directories(rem PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/rem/include
)

target_link_libraries(rem PUBLIC re)

# speex 라이브러리
add_library(speex STATIC
        speex/libspeex/bits.c
        speex/libspeex/modes.c
        speex/libspeex/nb_celp.c
        speex/libspeex/sb_celp.c
        speex/libspeex/ltp.c
        speex/libspeex/quant_lsp.c
        speex/libspeex/lsp.c
        speex/libspeex/lpc.c
        speex/libspeex/filters.c
        speex/libspeex/cb_search.c
        speex/libspeex/gain_table.c
        speex/libspeex/fftwrap.c
        speex/libspeex/smallft.c
        speex/libspeex/speex.c
        speex/libspeex/speex_callbacks.c
        speex/libspeex/vbr.c
        speex/libspeex/exc_5_64_table.c
        speex/libspeex/exc_5_256_table.c
        speex/libspeex/exc_8_128_table.c
        speex/libspeex/exc_10_16_table.c
        speex/libspeex/exc_10_32_table.c
        speex/libspeex/hexc_10_32_table.c
        speex/libspeex/exc_20_32_table.c
        speex/libspeex/hexc_table.c
        speex/libspeex/high_lsp_tables.c
        speex/libspeex/vq.c
        speex/libspeex/window.c
        speex/libspeex/kiss_fft.c
        speex/libspeex/kiss_fftr.c
        speex/libspeex/preprocess.c
)

target_include_directories(speex PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/speex/include
)

target_compile_definitions(speex PUBLIC
        FIXED_POINT
        EXPORT=
        USE_KISS_FFT
)

# g722 라이브러리
add_library(g722 STATIC
        g722/g722_decode.c
        g722/g722_encode.c
)

target_include_directories(g722 PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/g722
)

# gsm 라이브러리
add_library(gsm STATIC
        gsm/src/add.c
        gsm/src/code.c
        gsm/src/debug.c
        gsm/src/decode.c
        gsm/src/gsm_create.c
        gsm/src/gsm_decode.c
        gsm/src/gsm_destroy.c
        gsm/src/gsm_encode.c
        gsm/src/gsm_explode.c
        gsm/src/gsm_implode.c
        gsm/src/gsm_option.c
        gsm/src/gsm_print.c
        gsm/src/long_term.c
        gsm/src/lpc.c
        gsm/src/preprocess.c
        gsm/src/rpe.c
        gsm/src/short_term.c
        gsm/src/table.c
)

target_include_directories(gsm PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/gsm/inc
)

target_compile_definitions(gsm PUBLIC
        GSM_INTERNAL_SAMPLE
        HAS_STDLIB_H
        HAS_STRING_H
        HAS_LIMITS_H
        WAV49
)

if (WIN32)
    target_compile_definitions(gsm PUBLIC
            HAVE_STRING_H
            WIN32
            NDEBUG
            _WINDOWS
    )
    # Windows용 GSM 설정
    target_compile_definitions(gsm PUBLIC -U_HAVE_UNISTD_H)
endif ()

# portaudio 라이브러리
add_library(portaudio STATIC
        portaudio/src/common/pa_trace.c
        portaudio/src/common/pa_allocation.c
        portaudio/src/common/pa_converters.c
        portaudio/src/common/pa_cpuload.c
        portaudio/src/common/pa_debugprint.c
        portaudio/src/common/pa_dither.c
        portaudio/src/common/pa_front.c
        portaudio/src/common/pa_process.c
        portaudio/src/common/pa_ringbuffer.c
        portaudio/src/common/pa_stream.c
)

if (WIN32)
    target_sources(portaudio PRIVATE
        portaudio/src/hostapi/dsound/pa_win_ds_dynlink.c 
		portaudio/src/hostapi/dsound/pa_win_ds.c 
		portaudio/src/os/win/pa_x86_plain_converters.c 
		portaudio/src/os/win/pa_win_coinitialize.c 
        portaudio/src/os/win/pa_win_hostapis.c 
        portaudio/src/os/win/pa_win_util.c 
        portaudio/src/os/win/pa_win_waveformat.c 
        portaudio/src/os/win/pa_win_wdmks_utils.c
    )
    target_compile_definitions(portaudio PUBLIC
            PA_USE_WMME=1
    )
    target_link_libraries(portaudio PUBLIC winmm)
#elseif (APPLE)
#    target_sources(portaudio PRIVATE
#            portaudio/src/os/unix/pa_unix_hostapis.c
#            portaudio/src/os/unix/pa_unix_util.c
#            portaudio/src/hostapi/coreaudio/pa_mac_core.c
#            portaudio/src/hostapi/coreaudio/pa_mac_core_blocking.c
#            portaudio/src/hostapi/coreaudio/pa_mac_core_utilities.c
#    )
#    target_compile_definitions(portaudio PUBLIC
#            PA_USE_COREAUDIO=1
#    )
#    target_link_libraries(portaudio PUBLIC "-framework CoreAudio" "-framework AudioToolbox" "-framework AudioUnit" "-framework CoreServices")
else () # Linux
    target_sources(portaudio PRIVATE
            portaudio/src/os/unix/pa_unix_hostapis.c
            portaudio/src/os/unix/pa_unix_util.c
    )
    target_compile_definitions(portaudio PUBLIC
            PA_USE_ALSA=1
    )
    # ALSA 라이브러리 찾아 링크
    find_package(ALSA REQUIRED)
    target_link_libraries(portaudio PUBLIC ${ALSA_LIBRARIES})
endif ()

target_include_directories(portaudio PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/portaudio/include
        ${CMAKE_CURRENT_SOURCE_DIR}/portaudio/src/common
)

# webrtc 라이브러리 (WebRTC 음향 처리)
add_library(webrtc STATIC
        webrtc/webrtc/modules/audio_processing/aec/aec_core.c
        webrtc/webrtc/modules/audio_processing/aec/aec_core_sse2.c
        webrtc/webrtc/modules/audio_processing/aec/aec_rdft.c
        webrtc/webrtc/modules/audio_processing/aec/aec_rdft_sse2.c
        webrtc/webrtc/modules/audio_processing/aec/aec_resampler.c
        webrtc/webrtc/modules/audio_processing/aec/echo_cancellation.c
        webrtc/webrtc/modules/audio_processing/aecm/aecm_core.c
        webrtc/webrtc/modules/audio_processing/aecm/aecm_core_c.c
        webrtc/webrtc/modules/audio_processing/aecm/echo_control_mobile.c
        webrtc/webrtc/modules/audio_processing/utility/delay_estimator.c
        webrtc/webrtc/modules/audio_processing/utility/delay_estimator_wrapper.c
        webrtc/webrtc/modules/audio_processing/ns/noise_suppression.c
        webrtc/webrtc/modules/audio_processing/ns/noise_suppression_x.c
        webrtc/webrtc/modules/audio_processing/ns/ns_core.c
        webrtc/webrtc/modules/audio_processing/ns/nsx_core.c
        webrtc/webrtc/modules/audio_processing/ns/nsx_core_c.c
        webrtc/webrtc/common_audio/ring_buffer.c
        webrtc/webrtc/common_audio/signal_processing/auto_corr_to_refl_coef.c
        webrtc/webrtc/common_audio/signal_processing/auto_correlation.c
        webrtc/webrtc/common_audio/signal_processing/complex_bit_reverse.c
        webrtc/webrtc/common_audio/signal_processing/complex_fft.c
        webrtc/webrtc/common_audio/signal_processing/copy_set_operations.c
        webrtc/webrtc/common_audio/signal_processing/cross_correlation.c
        webrtc/webrtc/common_audio/signal_processing/division_operations.c
        webrtc/webrtc/common_audio/signal_processing/dot_product_with_scale.c
        webrtc/webrtc/common_audio/signal_processing/downsample_fast.c
        webrtc/webrtc/common_audio/signal_processing/energy.c
        webrtc/webrtc/common_audio/signal_processing/filter_ar.c
        webrtc/webrtc/common_audio/signal_processing/filter_ar_fast_q12.c
        webrtc/webrtc/common_audio/signal_processing/filter_ma_fast_q12.c
        webrtc/webrtc/common_audio/signal_processing/get_hanning_window.c
        webrtc/webrtc/common_audio/signal_processing/get_scaling_square.c
        webrtc/webrtc/common_audio/signal_processing/ilbc_specific_functions.c
        webrtc/webrtc/common_audio/signal_processing/levinson_durbin.c
        webrtc/webrtc/common_audio/signal_processing/lpc_to_refl_coef.c
        webrtc/webrtc/common_audio/signal_processing/min_max_operations.c
        webrtc/webrtc/common_audio/signal_processing/randomization_functions.c
        webrtc/webrtc/common_audio/signal_processing/real_fft.c
        webrtc/webrtc/common_audio/signal_processing/refl_coef_to_lpc.c
        webrtc/webrtc/common_audio/signal_processing/resample.c
        webrtc/webrtc/common_audio/signal_processing/resample_48khz.c
        webrtc/webrtc/common_audio/signal_processing/resample_by_2.c
        webrtc/webrtc/common_audio/signal_processing/resample_by_2_internal.c
        webrtc/webrtc/common_audio/signal_processing/resample_fractional.c
        webrtc/webrtc/common_audio/signal_processing/spl_init.c
        webrtc/webrtc/common_audio/signal_processing/spl_sqrt.c
        webrtc/webrtc/common_audio/signal_processing/spl_sqrt_floor.c
        webrtc/webrtc/common_audio/signal_processing/sqrt_of_one_minus_x_squared.c
        webrtc/webrtc/common_audio/signal_processing/vector_scaling_operations.c
        webrtc/webrtc/system_wrappers/source/cpu_features.c
)

target_include_directories(webrtc PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/webrtc
)

# baresip 라이브러리 (SIP 엔진)
add_library(baresip STATIC
        baresip/include/baresip.h
        baresip/modules/dialog_info/dialog_info.c baresip/modules/dialog_info/dialog_info.h
        baresip/modules/dialog_info/dialog_info_subscriber.c
        baresip/modules/g711/g711.c
        baresip/modules/g722/g722.c
        baresip/modules/g726_32/g726.c baresip/modules/g726_32/g726.h
        baresip/modules/g726_32/g726_32.c
        baresip/modules/gsm/gsm.c
        baresip/modules/l16/l16.c
        baresip/modules/mwi/mwi.c
        baresip/modules/portaudio/portaudio.c
        baresip/modules/presence/notifier.c
        baresip/modules/presence/presence.c baresip/modules/presence/presence.h
        baresip/modules/presence/subscriber.c
        baresip/modules/qtaudio/audioio.h
        baresip/modules/qtaudio/qtaudio.c baresip/modules/qtaudio/qtaudio.h
        baresip/modules/qtaudio/qtaudio_in.cpp
        baresip/modules/qtaudio/qtaudio_out.cpp
        baresip/modules/recorder/wavfile.h
        baresip/modules/softvol/softvol.c
        baresip/modules/speex/speex.c
        baresip/modules/speex_aec/speex_aec.c
        baresip/modules/speex_pp/speex_pp.c
        baresip/modules/stun/stun.c
        baresip/modules/webrtc_aec/webrtc_aec.c
        baresip/src/account.c
        baresip/src/aucodec.c
        baresip/src/audio.c
        baresip/src/aufilt.c
        baresip/src/auplay.c
        baresip/src/ausrc.c
        baresip/src/bfcp.c
        baresip/src/call.c
        baresip/src/cmd.c
        baresip/src/conf.c
        baresip/src/config.c
        baresip/src/contact.c
        baresip/src/core.h
        baresip/src/magic.h
        baresip/src/mctrl.c
        baresip/src/menc.c
        baresip/src/message.c
        baresip/src/mnat.c
        baresip/src/module.c
        baresip/src/net.c
        baresip/src/paging_tx.c
        baresip/src/play.c
        baresip/src/reg.c
        baresip/src/rtpkeep.c
        baresip/src/sdp.c
        baresip/src/sipreq.c
        baresip/src/static.c
        baresip/src/stream.c
        baresip/src/ua.c
)

target_include_directories(baresip PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/baresip/include
)

target_link_libraries(baresip PUBLIC
        re
        rem
        g722
        gsm
        portaudio
        speex
        webrtc
        Qt::Core
        Qt::Multimedia
)

target_compile_definitions(baresip PUBLIC STATIC)

if (WIN32)
    target_sources(baresip PRIVATE
            baresip/modules/aufile/aufile.c
            baresip/modules/recorder/recorder.c
            baresip/modules/recorder/wavfile.c
            baresip/modules/winwave/src.c
            baresip/modules/winwave/winwave.c baresip/modules/winwave/winwave.h
            baresip/modules/winwave/winwave_play.c
    )
    target_link_libraries(baresip PUBLIC ws2_32 winmm)
endif ()

# qSIP 애플리케이션
add_executable(qSIP
        qSIP/resources.qrc
        qSIP/AbstractSettingForm.cpp qSIP/AbstractSettingForm.h
        qSIP/Account.h
        qSIP/ClearButton.cpp qSIP/ClearButton.h
        qSIP/joinpath.cpp qSIP/joinpath.h
        qSIP/main.cpp qSIP/main.h
        qSIP/MainWindow.cpp qSIP/MainWindow.h
        qSIP/MainWindow.ui
        qSIP/misc.cpp qSIP/misc.h
        qSIP/MySettings.cpp qSIP/MySettings.h
        qSIP/Network.cpp qSIP/Network.h
        qSIP/PhoneThread.cpp qSIP/PhoneThread.h
        qSIP/PhoneWidget.cpp qSIP/PhoneWidget.h
        qSIP/PhoneWidget.ui
        qSIP/SettingAccountForm.cpp qSIP/SettingAccountForm.h
        qSIP/SettingAccountForm.ui
        qSIP/SettingAudioDeviceForm.cpp qSIP/SettingAudioDeviceForm.h
        qSIP/SettingAudioDeviceForm.ui
        qSIP/SettingsDialog.cpp qSIP/SettingsDialog.h
        qSIP/SettingsDialog.ui
        qSIP/StatusLabel.cpp qSIP/StatusLabel.h
)

target_include_directories(qSIP PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/baresip/include
        ${CMAKE_CURRENT_SOURCE_DIR}/re/include
        ${CMAKE_CURRENT_SOURCE_DIR}/rem/include
)

target_link_libraries(qSIP PUBLIC
        baresip
        Qt::Core
        Qt::Multimedia
        Qt::Widgets
        Qt::Gui
)

if (WIN32)
    target_link_libraries(qSIP PUBLIC ws2_32 winmm)
endif ()

# 설치 규칙
install(TARGETS qSIP
        RUNTIME DESTINATION bin
)
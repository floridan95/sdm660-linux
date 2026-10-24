// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 Daniel Florian <daniel.florian@floridan.net>
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved.

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/device-id/of.h>
#include <linux/gpio/consumer.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct ft8716u_b2n {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator *iovcc;
	struct gpio_desc *reset_gpio;
};

static inline
struct ft8716u_b2n *to_ft8716u_b2n(struct drm_panel *panel)
{
	return container_of_const(panel, struct ft8716u_b2n, panel);
}

static void ft8716u_b2n_reset(struct ft8716u_b2n *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(1000, 2000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(1000, 2000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
}

static int ft8716u_b2n_on(struct ft8716u_b2n *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x87, 0x16, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x87, 0x16);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_set_column_address_multi(&dsi_ctx, 0x0000, 0x0437);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_set_page_address_multi(&dsi_ctx, 0x0000, 0x086f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xca,
				     0x80, 0xcc, 0xff, 0xa5, 0xff, 0x80, 0xff,
				     0x00, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0xb0, 0xab, 0xbc, 0xaa, 0xdc, 0xab, 0xaa,
				     0xca, 0xbb, 0xbc, 0x88, 0x78, 0x56, 0x34,
				     0x33, 0x33, 0x33, 0x33);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x11);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0xa0, 0xab, 0xac, 0x9b, 0xdb, 0x9b, 0xaa,
				     0xab, 0xbb, 0xcb, 0x88, 0x88, 0x67, 0x35,
				     0x33, 0x33, 0x33, 0x33);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x12);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0xa0, 0xaa, 0x9c, 0x9b, 0xcb, 0xab, 0xa9,
				     0xaa, 0xab, 0xca, 0x88, 0x88, 0x67, 0x45,
				     0x44, 0x44, 0x34, 0x33);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x13);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0xa0, 0x9a, 0xab, 0x8b, 0xcb, 0xaa, 0xa9,
				     0xb9, 0xaa, 0xba, 0x88, 0x88, 0x78, 0x46,
				     0x44, 0x44, 0x44, 0x44);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x14);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x90, 0xaa, 0xaa, 0x9a, 0xca, 0x9a, 0xa9,
				     0xa9, 0xaa, 0xaa, 0x88, 0x88, 0x78, 0x56,
				     0x55, 0x55, 0x44, 0x44);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x15);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x90, 0x9a, 0x8b, 0x9b, 0xb9, 0x9b, 0x99,
				     0xa9, 0xb9, 0xa9, 0x88, 0x88, 0x78, 0x56,
				     0x55, 0x55, 0x55, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x16);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x90, 0x9a, 0x9a, 0x8a, 0xc9, 0x9a, 0x89,
				     0x9a, 0xaa, 0xa8, 0x88, 0x88, 0x88, 0x67,
				     0x56, 0x55, 0x55, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x17);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x90, 0x99, 0x9a, 0x8a, 0xb9, 0x9a, 0x98,
				     0x99, 0xa9, 0x99, 0x88, 0x88, 0x88, 0x67,
				     0x66, 0x66, 0x56, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x18);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x90, 0x99, 0x8a, 0x99, 0xb8, 0x99, 0x89,
				     0x9a, 0x99, 0x99, 0x88, 0x88, 0x88, 0x67,
				     0x66, 0x66, 0x66, 0x66);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x19);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x90, 0x98, 0x8a, 0x99, 0xa8, 0xa9, 0x98,
				     0x98, 0x99, 0x99, 0x88, 0x88, 0x88, 0x78,
				     0x67, 0x66, 0x66, 0x66);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x1a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x80, 0x99, 0x99, 0x89, 0xa8, 0x99, 0x98,
				     0x98, 0x99, 0x89, 0x88, 0x88, 0x88, 0x78,
				     0x77, 0x77, 0x66, 0x66);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x1b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x80, 0x98, 0x99, 0x89, 0x98, 0x99, 0x98,
				     0x98, 0x98, 0x89, 0x88, 0x88, 0x88, 0x78,
				     0x77, 0x77, 0x77, 0x67);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x1c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x80, 0x98, 0x98, 0x89, 0x98, 0x89, 0x89,
				     0x98, 0x98, 0x89, 0x88, 0x88, 0x88, 0x88,
				     0x77, 0x77, 0x77, 0x77);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x1d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x80, 0x88, 0x89, 0x89, 0x88, 0x99, 0x88,
				     0x98, 0x98, 0x88, 0x88, 0x88, 0x88, 0x88,
				     0x88, 0x78, 0x77, 0x77);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x1e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x80, 0x88, 0x98, 0x88, 0x88, 0x89, 0x89,
				     0x88, 0x98, 0x88, 0x88, 0x88, 0x88, 0x88,
				     0x88, 0x88, 0x78, 0x77);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x1f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x80, 0x88, 0x88, 0x88, 0x88, 0x89, 0x88,
				     0x88, 0x98, 0x87, 0x88, 0x88, 0x88, 0x88,
				     0x88, 0x88, 0x88, 0x88);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0xb5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xca, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0xa3);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xca,
				     0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 0xc8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0xb2);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xca, 0x04);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x81);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0xf8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x82);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0xe1);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x83);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x84);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0xf8);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x85);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0xe1);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x86);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x87);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x88);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0x1c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x89);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x8a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x8b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0x1c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x8c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5, 0x01, 0x00, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x88);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3, 0x33, 0x33);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x98);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3, 0x33, 0x33);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x00, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x00, 0x00);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x2c);

	return dsi_ctx.accum_err;
}

static int ft8716u_b2n_off(struct ft8716u_b2n *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_usleep_range(&dsi_ctx, 10000, 11000);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 150);

	return dsi_ctx.accum_err;
}

static int ft8716u_b2n_prepare(struct drm_panel *panel)
{
	struct ft8716u_b2n *ctx = to_ft8716u_b2n(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_enable(ctx->iovcc);
	if (ret < 0) {
		dev_err(dev, "Failed to enable iovcc: %d\n", ret);
		return ret;
	}

	ft8716u_b2n_reset(ctx);

	ret = ft8716u_b2n_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_disable(ctx->iovcc);
		return ret;
	}

	return 0;
}

static int ft8716u_b2n_unprepare(struct drm_panel *panel)
{
	struct ft8716u_b2n *ctx = to_ft8716u_b2n(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = ft8716u_b2n_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_disable(ctx->iovcc);

	return 0;
}

static const struct drm_display_mode ft8716u_b2n_mode = {
	.clock = (1080 + 32 + 2 + 32) * (2160 + 16 + 2 + 16) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 32,
	.hsync_end = 1080 + 32 + 2,
	.htotal = 1080 + 32 + 2 + 32,
	.vdisplay = 2160,
	.vsync_start = 2160 + 16,
	.vsync_end = 2160 + 16 + 2,
	.vtotal = 2160 + 16 + 2 + 16,
	.width_mm = 68,
	.height_mm = 136,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int ft8716u_b2n_get_modes(struct drm_panel *panel,
				 struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &ft8716u_b2n_mode);
};

static const struct drm_panel_funcs ft8716u_b2n_panel_funcs = {
	.prepare = ft8716u_b2n_prepare,
	.unprepare = ft8716u_b2n_unprepare,
	.get_modes = ft8716u_b2n_get_modes,
};

static int ft8716u_b2n_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int ft8716u_b2n_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness & 0xff;
}

static const struct backlight_ops ft8716u_b2n_bl_ops = {
	.update_status = ft8716u_b2n_bl_update_status,
	.get_brightness = ft8716u_b2n_bl_get_brightness,
};

static struct backlight_device *
ft8716u_b2n_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 255,
		.max_brightness = 255,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &ft8716u_b2n_bl_ops, &props);
}

static int ft8716u_b2n_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct ft8716u_b2n *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct ft8716u_b2n, panel,
				   &ft8716u_b2n_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ctx->iovcc = devm_regulator_get(dev, "iovcc");
	if (IS_ERR(ctx->iovcc))
		return dev_err_probe(dev, PTR_ERR(ctx->iovcc),
				     "Failed to get iovcc\n");

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_MODE_VIDEO_HSE |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS;

	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = ft8716u_b2n_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	ret = devm_drm_panel_add(dev, &ctx->panel);
	if (ret)
		return ret;

	return devm_mipi_dsi_attach(dev, dsi);
}

static const struct of_device_id ft8716u_b2n_of_match[] = {
	{ .compatible = "focaltech,ft8716u-b2n" },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, ft8716u_b2n_of_match);

static struct mipi_dsi_driver ft8716u_b2n_driver = {
	.probe = ft8716u_b2n_probe,
	.driver = {
		.name = "panel-ft8716u-b2n",
		.of_match_table = ft8716u_b2n_of_match,
	},
};
module_mipi_dsi_driver(ft8716u_b2n_driver);

MODULE_AUTHOR("Daniel Florian <daniel.florian@floridan.net>");
MODULE_DESCRIPTION("DRM driver for B2N ft8716u FHD video mode dsi panel");
MODULE_LICENSE("GPL");
